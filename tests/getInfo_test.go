package tests_test

import (
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

func TestCloudGetInfo(t *testing.T) {
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
		}).Expect()

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

	e.GET("/" + uuid).
		Expect().
		Status(http.StatusUnauthorized)

	e.GET("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		Expect().
		Status(http.StatusOK).
		JSON().IsNull()

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
		WithFile("file", tmpFile1.Name()).Expect()

	e.GET("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		Expect().
		Status(http.StatusOK).
		JSON().
		Array().
		ContainsOnly(filepath.Base(tmpFile1.Name()))

	tmpFile2, err := os.CreateTemp(t.TempDir(), "tempfile-*.txt")
	if err != nil {
		t.Fatalf("Failed to create temp file: %v", err)
	}
	defer os.Remove(tmpFile2.Name())

	if _, err := tmpFile2.WriteString(gofakeit.Comment()); err != nil {
		t.Fatalf("Failed to write to temp file: %v", err)
	}

	tmpFile2.Close()

	e.POST("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		WithMultipart().
		WithFile("file", tmpFile2.Name()).Expect()

	e.GET("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		Expect().
		Status(http.StatusOK).
		JSON().
		Array().
		ContainsAll(
			filepath.Base(tmpFile1.Name()),
			filepath.Base(tmpFile2.Name()),
		)
}
