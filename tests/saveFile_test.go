package tests_test

import (
	"log/slog"
	"net/http"
	"net/url"
	"os"
	"testing"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/login"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/registration"
	"github.com/brianvoe/gofakeit/v7"
	"github.com/gavv/httpexpect/v2"
)

func TestCloudSaveFile(t *testing.T) {
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
		}).Expect().Status(http.StatusCreated)

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

	fileContent := []byte("This is a test file content")
	filenames := []string{
		" ",
		"..\\..\\windows\\system32\\drivers\\etc\\hosts",
		"*.txt",
		"file[1-9].dat",
		"secret?file",
		"file\nwith\rnewline",
		"file\twith\ttabs",
		".htaccess",
		".bashrc",
		".env",
		"file name with spaces.txt",
		"file\"name\".txt",
		"file;echo 1",
		"fi\u202Ele.txt",
		"file\u200Bname.txt",
	}

	// Попытка сохранение файла с опасным именнем
	for _, filename := range filenames {
		tmpFile, err := os.Create(filename)
		if err != nil {
			slog.Error("Failed to create temp file: %v", slog.String("err", err.Error()))

			continue
		}
		defer os.Remove(tmpFile.Name())

		if _, err := tmpFile.Write(fileContent); err != nil {
			t.Fatalf("Failed to write to temp file: %v", err)
		}

		tmpFile.Close()

		e.POST("/"+uuid).
			WithHeader("Authorization", "Bearer "+token).
			WithMultipart().
			WithFile("file", tmpFile.Name()).
			Expect().
			Status(http.StatusBadRequest)
	}

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
		WithMultipart().
		WithFile("file", tmpFile1.Name()).
		Expect().
		Status(http.StatusUnauthorized)

	e.POST("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		WithMultipart().
		WithFile("file", tmpFile1.Name()).
		Expect().
		Status(http.StatusCreated)

	e.POST("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		WithMultipart().
		WithFile("file", tmpFile1.Name()).
		Expect().
		Status(http.StatusConflict)

	fakeEmail = gofakeit.Email()
	fakePassword = gofakeit.Password(true, true, true, true, true, 10)

	e.POST("/registration").
		WithJSON(registration.UserRequest{
			Email:          fakeEmail,
			Password:       fakePassword,
			SpaceAvailable: 1,
		}).Expect().Status(http.StatusCreated)

	loginResp = e.POST("/login").
		WithJSON(login.UserRequest{
			Email:    fakeEmail,
			Password: fakePassword,
		}).
		Expect().
		Status(http.StatusOK).
		JSON()

	token = loginResp.Path("$.token").String().NotEmpty().Raw()
	uuid = loginResp.Path("$.uuid").String().NotEmpty().Raw()

	e.POST("/"+uuid).
		WithHeader("Authorization", "Bearer "+token).
		WithMultipart().
		WithFile("file", tmpFile1.Name()).
		Expect().
		Status(http.StatusConflict)
}
