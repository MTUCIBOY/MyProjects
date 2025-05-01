package tests_test

import (
	"net/http"
	"net/url"
	"testing"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/registration"
	"github.com/brianvoe/gofakeit/v7"
	"github.com/gavv/httpexpect/v2"
)

const (
	host = "localhost:8888"
)

func TestCloudRegistration(t *testing.T) {
	t.Parallel()

	u := url.URL{
		Scheme: "https",
		Host:   host,
	}

	e := httpexpect.Default(t, u.String())

	fakeEmail := gofakeit.Email()

	// Good script
	e.POST("/registration").
		WithJSON(registration.UserRequest{
			Email:          fakeEmail,
			Password:       gofakeit.Password(true, true, true, true, true, 10),
			SpaceAvailable: gofakeit.Int64(),
		}).
		Expect().
		Status(http.StatusCreated)

	// Bad script
	e.POST("/registration").
		WithJSON(registration.UserRequest{
			Email:          fakeEmail,
			Password:       gofakeit.Password(true, true, true, true, true, 10),
			SpaceAvailable: gofakeit.Int64(),
		}).
		Expect().
		Status(http.StatusConflict)

	e.POST("/registration").
		WithJSON(registration.UserRequest{
			Email:          gofakeit.Email(),
			Password:       "",
			SpaceAvailable: gofakeit.Int64(),
		}).
		Expect().
		Status(http.StatusBadRequest)

	e.POST("/registration").
		WithJSON(registration.UserRequest{
			Email:          gofakeit.Email(),
			Password:       gofakeit.Password(true, true, true, true, true, 10),
			SpaceAvailable: 0,
		}).
		Expect().
		Status(http.StatusBadRequest)

	e.POST("/registration").
		WithJSON(registration.UserRequest{
			Email:          gofakeit.Email(),
			Password:       gofakeit.Password(true, true, true, true, true, 10),
			SpaceAvailable: -1,
		}).
		Expect().
		Status(http.StatusBadRequest)
}
