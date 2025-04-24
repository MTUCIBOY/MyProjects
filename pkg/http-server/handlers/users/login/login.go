// login пакет для хендлера login.
// Создает JWT для пользователя для получения доступа к базе.
package login

import (
	"context"
	"encoding/json"
	"log/slog"
	"net/http"
	"time"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/middleware/auth"
	"github.com/go-chi/chi/v5/middleware"
)

// loginUser интерфейс для работы с БД. Нужная абстракция, если БД будет меняться.
type loginUser interface {
	UserID(ctx context.Context, email string) (string, error)
	ComparePassword(ctx context.Context, userID, password string) error
}

// loginRequest структура запроса пользователя. Нужна для парсинга тела запроса.
type loginRequest struct {
	Email    string `json:"email"`
	Password string `json:"password"`
}

// New функция для создания хендлера login.
func New(log *slog.Logger, loginUser loginUser, tokenTTL time.Duration) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.users.login.New"
		log := log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		var req loginRequest
		if err := json.NewDecoder(r.Body).Decode(&req); err != nil {
			log.Error("failed to decode request body", slog.String("err", err.Error()))
			http.Error(w, "Invalid request body", http.StatusBadRequest)

			return
		}

		uuid, err := loginUser.UserID(r.Context(), req.Email)
		if err != nil {
			log.Error("failed to get userID", slog.String("err", err.Error()))
			http.Error(w, "Invalid email or password", http.StatusUnauthorized)

			return
		}

		if err := loginUser.ComparePassword(r.Context(), uuid, req.Password); err != nil {
			log.Error("failed to compare password", slog.String("err", err.Error()))
			http.Error(w, "Invalid email or password", http.StatusUnauthorized)

			return
		}

		_, tokenString, err := auth.TokenAuth.Encode(map[string]any{
			"sub": uuid,
			"exp": time.Now().Add(tokenTTL).Unix(),
		})
		if err != nil {
			log.Error("failed to generate JWT", slog.String("err", err.Error()))
			http.Error(w, "Failed to generate auth token", http.StatusInternalServerError)

			return
		}

		w.Header().Set("Content-Type", "application/json")
		json.NewEncoder(w).Encode(map[string]any{
			"token": tokenString,
			"uuid":  uuid,
		})
	}
}
