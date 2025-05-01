// userdeleter пакет хендлера UserDeleter
// Нужен для того, чтобы удалить пользователя из облака.
// Удаляет информацию с БД и все файлы с облака.
package userdeleter

import (
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"log/slog"
	"net/http"
	"os"
	"path/filepath"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/storage"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

// DelUser интерфейс для работы с БД. Нужная абстракция, если БД будет меняться.
type delUser interface {
	DeleteUser(ctx context.Context, userID string) error
	ComparePassword(ctx context.Context, userID, password string) error
	AllFiles(ctx context.Context, userID string) ([]string, error)
}

// DelRequest структура запроса пользователя. Нужна для парсинга тела запроса.
type DelRequest struct {
	Password string `json:"password"`
}

// New функция для создания хендлера deletion.
func New(log *slog.Logger, delUser delUser) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.users.userDeleter.New"
		log := log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		userID := chi.URLParam(r, "userID")
		if userID == "" {
			log.Error(files.ErrMissingUserID.Error())
			http.Error(w, "User ID is required", http.StatusBadRequest)

			return
		}

		var delr DelRequest
		if err := json.NewDecoder(r.Body).Decode(&delr); err != nil {
			log.Error("failed to decode request body", slog.String("err", err.Error()))
			http.Error(w, "Bad request", http.StatusBadRequest)

			return
		}

		err := delUser.ComparePassword(r.Context(), userID, delr.Password)
		if err != nil {
			if errors.Is(err, storage.ErrUserNotFound) {
				log.Error(storage.ErrUserNotFound.Error())
				http.Error(w, "User not exists", http.StatusNotFound)

				return
			}

			log.Error("password does not match", slog.String("err", err.Error()))
			http.Error(w, "Wrong password", http.StatusUnauthorized)

			return
		}

		filesname, err := delUser.AllFiles(r.Context(), userID)
		if err != nil {
			log.Error("failed to get user files", slog.String("err", err.Error()))
			http.Error(w, "Failed to get list of files", http.StatusInternalServerError)
		}

		if err := deleteFiles(log, w, userID, filesname); err != nil {
			return
		}

		err = delUser.DeleteUser(r.Context(), userID)
		if err != nil {
			log.Error("failed to delete user from DB", slog.String("err", err.Error()))
			http.Error(w, "Failed to delete user", http.StatusInternalServerError)

			return
		}

		log.Info("User deleted successfully", slog.String("userID", userID))

		w.WriteHeader(http.StatusOK)
	}
}

// deleteFiles функция удаления файлов пользователя с облака.
func deleteFiles(log *slog.Logger, w http.ResponseWriter, userID string, filesname []string) error {
	for _, filename := range filesname {
		filePath := filepath.Join(files.BaseDir, userID, filename)

		err := os.Remove(filePath)
		if err != nil {
			log.Error("error removing file from disk", slog.String("err", err.Error()))
			http.Error(w, "Failed delete file", http.StatusInternalServerError)

			return fmt.Errorf("error removing file from disk: %w", err)
		}
	}

	return nil
}
