// infogeter пакет для хендлера getInfo.
// Получает список файлов в своем облаке в формате json.
package infogeter

import (
	"context"
	"encoding/json"
	"log/slog"
	"net/http"

	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

// BaseInfo интерфейс для работы с БД. Нужная абстракция, если БД будет меняться.
type baseInfo interface {
	AllFiles(ctx context.Context, userID string) ([]string, error)
}

// New функция для создания хендлера getInfo.
func New(log *slog.Logger, baseinfo baseInfo) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.files.infogeter.New"
		log := log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		userID := chi.URLParam(r, "userID")
		if userID == "" {
			log.Error("missing userID")
			http.Error(w, "User ID is required", http.StatusBadRequest)

			return
		}

		filenames, err := baseinfo.AllFiles(r.Context(), userID)
		if err != nil {
			log.Error("failed to get slice of files", slog.String("err", err.Error()))
			http.Error(w, "Failed to get user files", http.StatusInternalServerError)

			return
		}

		w.Header().Set("Content-Type", "application/json")

		if err := json.NewEncoder(w).Encode(filenames); err != nil {
			log.Error("failed to encode files", slog.String("err", err.Error()))
			http.Error(w, "Failed to encode response", http.StatusInternalServerError)

			return
		}

		log.Info("User files sent successfully")
	}
}
