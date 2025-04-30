// auth пакет для аутентифакации.
// Создает токен из секретного ключа из переменной окружения.
package auth

import (
	"crypto/rand"
	"log"
	"log/slog"
	"net/http"

	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
	"github.com/go-chi/jwtauth/v5"
)

const keyLength = 32

// TokenAuth переменная для создания и проверки JWT.
var TokenAuth *jwtauth.JWTAuth

// init создание TokenAuth.
func init() {
	randomKey := make([]byte, keyLength)

	// rand.Read паникует в случае ошибки.
	_, err := rand.Read(randomKey)
	if err != nil {
		log.Fatal(err)
	}

	TokenAuth = jwtauth.New("HS256", randomKey, nil)
}

// CompareUUIDMiddleware мидлвейр для проверки UUID из URL и из JWT.
func CompareUUIDMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		const fn = "middleware.auth.CompareUUIDMiddleware"
		log := slog.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		_, claims, err := jwtauth.FromContext(r.Context())
		if err != nil {
			log.Error("failed to get token from contex", slog.String("err", err.Error()))
			http.Error(w, "Bad auth token", http.StatusUnauthorized)

			return
		}

		jwtUUID, ok := claims["sub"].(string)
		if !ok {
			log.Error("missing uuid in token")
			http.Error(w, "Invalid token", http.StatusUnauthorized)

			return
		}

		urlUUID := chi.URLParam(r, "userID")

		if jwtUUID != urlUUID {
			http.Error(w, "Access denide", http.StatusForbidden)

			return
		}

		next.ServeHTTP(w, r)
	})
}
