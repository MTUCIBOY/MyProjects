package tests_test

import (
	"fmt"
	"net/http"
	"net/url"
	"os"
	"path/filepath"
	"testing"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/login"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/registration"
	"github.com/brianvoe/gofakeit/v7"
	"github.com/gavv/httpexpect/v2"
)

func TestCloudSendFile(t *testing.T) {
	u := url.URL{
		Scheme: "https",
		Host:   host,
	}

	e := httpexpect.Default(t, u.String())

	fakeEmail := gofakeit.Email()
	fakePassword := gofakeit.Password(true, true, true, true, true, 10)

	e.POST("/registration").
		WithJSON(registration.UserRequest{
			Email:          fakeEmail,
			Password:       fakePassword,
			SpaceAvailable: gofakeit.Int64(),
		}).
		Expect().
		Status(http.StatusCreated)

	loginResp := e.POST("/login").
		WithJSON(login.UserRequest{
			Email:    fakeEmail,
			Password: fakePassword,
		}).
		Expect().
		Status(http.StatusOK).
		JSON()

	token := loginResp.Path("$.token").String().NotEmpty().Raw()
	uuid := loginResp.Path("$.uuid").String().NotEmpty().Raw()

	tmpFile1, err := os.CreateTemp(t.TempDir(), "tempfile-*.txt")
	if err != nil {
		t.Fatalf("Failed to create temp file: %v", err)
	}
	defer os.Remove(tmpFile1.Name())

	if _, err := tmpFile1.WriteString(gofakeit.Comment()); err != nil {
		t.Fatalf("Failed to write to temp file: %v", err)
	}

	tmpFile1.Close()

	e.POST("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		WithMultipart().
		WithFile("file", tmpFile1.Name()).
		Expect().
		Status(http.StatusCreated)

	e.GET(filepath.Join("/", uuid, filepath.Base(tmpFile1.Name()))).
		Expect().
		Status(http.StatusUnauthorized)

	resp := e.GET(filepath.Join("/", uuid, filepath.Base(tmpFile1.Name()))).
		WithHeader("Authorization", "Bearer "+token).
		Expect().
		Status(http.StatusOK)

	resp.Header("Content-Type").IsEqual("application/octet-stream")
	resp.Header("Content-Disposition").Contains("attachment; filename=")

	body := resp.Body().Raw()
	if len(body) == 0 {
		t.Fatalf("Downloaded file is empty")
	}

	fmt.Println(filepath.Join("/", uuid, filepath.Base("not_exits")))

	e.GET(filepath.Join("/", uuid, filepath.Base("not_exits"))).
		WithHeader("Authorization", "Bearer "+token).
		Expect().
		Status(http.StatusNotFound)
}
