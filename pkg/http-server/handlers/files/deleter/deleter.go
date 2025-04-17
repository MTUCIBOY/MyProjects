package deleter

import (
	"context"
	"errors"
	"log/slog"
	"net/http"
	"os"
	"path/filepath"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/storage"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

type FileDeleter interface {
	DeleteFile(ctx context.Context, userID, filename string) error
}

// New функция для создания хендлера send.
func New(log *slog.Logger, fileDeleter FileDeleter) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.files.deleter.New"
		log := log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		userID := chi.URLParam(r, "userID")
		filename := chi.URLParam(r, "filename")

		if userID == "" || filename == "" {
			log.Error(files.ErrMissingUserIDFilename.Error())
			http.Error(w, "User ID and filename is required", http.StatusBadRequest)

			return
		}

		err := fileDeleter.DeleteFile(r.Context(), userID, filename)
		if err != nil {
			if errors.Is(err, storage.ErrUserNotFound) {
				log.Error(storage.ErrUserNotFound.Error())
				http.Error(w, "User not found", http.StatusNotFound)

				return
			}

			if errors.Is(err, storage.ErrFileNotFound) {
				log.Error(storage.ErrFileExists.Error())
				http.Error(w, "File not found", http.StatusNotFound)

				return
			}

			log.Error("error in DB", slog.String("err", err.Error()))
			http.Error(w, "Failed delete file", http.StatusInternalServerError)

			return
		}

		filePath := filepath.Join(files.BaseDir, userID, filename)

		err = os.Remove(filePath)
		if err != nil {
			log.Error("error removing file from disk", slog.String("err", err.Error()))
			http.Error(w, "Failed delete file", http.StatusInternalServerError)

			return
		}

		log.Info("File deleted successfully", slog.String("filename", filename))

		w.WriteHeader(http.StatusOK)
	}
}
