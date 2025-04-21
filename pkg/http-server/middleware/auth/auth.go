package auth

import (
	"os"

	"github.com/go-chi/jwtauth/v5"
)

var TokenAuth *jwtauth.JWTAuth

func init() {
	secretKey := []byte(os.Getenv("JWT_SECRET"))
	TokenAuth = jwtauth.New("HS256", secretKey, nil)
}
