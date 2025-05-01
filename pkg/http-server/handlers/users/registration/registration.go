// registration пакет для хендлера registration.
// Регистрирует пользователей, информацию получает из JSON-файла.
package registration

import (
	"context"
	"encoding/json"
	"errors"
	"log/slog"
	"net/http"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/storage"
	"github.com/go-chi/chi/v5/middleware"
)

// RegUser интерфейс для работы с БД. Нужная абстракция, если БД будет меняться.
type regUser interface {
	NewUser(ctx context.Context, email, password string, spaceAvailable int64) error
}

// RegRequest структура запроса пользователя. Нужна для парсинга тела запроса.
type UserRequest struct {
	Email          string `json:"email"`
	Password       string `json:"password"`
	SpaceAvailable int64  `json:"space_available"`
}

// New функция для создания хендлера registration.
func New(log *slog.Logger, regUser regUser) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.users.registration.New"
		log := log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		var req UserRequest
		if err := json.NewDecoder(r.Body).Decode(&req); err != nil {
			log.Error("failed to parse request body", slog.String("err", err.Error()))
			http.Error(w, "Invalid request body", http.StatusBadRequest)

			return
		}

		err := regUser.NewUser(r.Context(), req.Email, req.Password, req.SpaceAvailable)
		if err != nil {
			if errors.Is(err, storage.ErrUserAlreadyExists) {
				log.Error(storage.ErrUserAlreadyExists.Error())
				http.Error(w, "User already exists", http.StatusConflict)

				return
			}

			if errors.Is(err, storage.ErrInvalidParams) {
				log.Error(storage.ErrInvalidParams.Error())
				http.Error(w, "Invalid params", http.StatusBadRequest)

				return
			}

			log.Error("failed to registraite user", slog.String("err", err.Error()))
			http.Error(w, "Failed to registrate new user", http.StatusInternalServerError)

			return
		}

		w.WriteHeader(http.StatusCreated)
	}
}
