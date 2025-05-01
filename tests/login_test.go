package tests_test

import (
	"net/http"
	"net/url"
	"testing"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/login"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/registration"
	"github.com/brianvoe/gofakeit/v7"
	"github.com/gavv/httpexpect/v2"
)

func TestCloudLogin(t *testing.T) {
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

	e.POST("/login").
		WithJSON(login.UserRequest{
			Email:    gofakeit.Email(),
			Password: fakePassword,
		}).
		Expect().
		Status(http.StatusUnauthorized)

	e.POST("/login").
		WithJSON(login.UserRequest{
			Email:    fakeEmail,
			Password: gofakeit.Password(true, true, true, true, true, 10),
		}).
		Expect().
		Status(http.StatusUnauthorized)

	e.POST("/login").
		WithJSON(login.UserRequest{
			Email:    fakeEmail,
			Password: fakePassword,
		}).
		Expect().
		Status(http.StatusOK).
		JSON().
		Object().
		ContainsKey("token").
		ContainsKey("uuid")
}
