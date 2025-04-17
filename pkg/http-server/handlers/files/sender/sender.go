// TODO: поменять ошибки, связать с пакетом files

// sender пакет для хендлера send.
// Нужен для отправки файлов с облака пользователю.
package sender

import (
	"context"
	"fmt"
	"io"
	"log/slog"
	"net/http"
	"os"
	"path/filepath"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

// FileSender интерфейс для работы с БД. Нужная абстракция, если БД будет меняться.
type FileSender interface {
	IsFileExist(ctx context.Context, userID, filename string) (bool, error)
}

// New функция для создания хендлера send.
func New(log *slog.Logger, fileSender FileSender) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.files.sender.New"
		l := log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		userID := chi.URLParam(r, "userID")
		filename := chi.URLParam(r, "filename")

		if userID == "" || filename == "" {
			l.Error("missing user ID or filename")
			http.Error(w, "User ID and filename are required", http.StatusBadRequest)

			return
		}

		exists, err := fileSender.IsFileExist(r.Context(), userID, filename)
		if err != nil {
			l.Error("failed to check file existence", slog.String("err", err.Error()))
			http.Error(w, "Failed to check file existence", http.StatusInternalServerError)

			return
		}

		if !exists {
			l.Error("file not found", slog.String("filename", filename))
			http.Error(w, "File not found", http.StatusNotFound)

			return
		}

		filePath := filepath.Join(files.BaseDir, userID, filename)

		file, err := os.Open(filePath)
		if err != nil {
			if os.IsNotExist(err) {
				l.Error("file not found on disk", slog.String("filename", filename))
				http.Error(w, "File not found", http.StatusNotFound)

				return
			}

			l.Error("failed to open file", slog.String("err", err.Error()))
			http.Error(w, "Failed to open file", http.StatusInternalServerError)

			return
		}
		defer file.Close()

		w.Header().Set("Content-Type", "application/octet-stream")
		w.Header().Set("Content-Disposition", fmt.Sprintf(`attachment; filename="%s"`, filename))

		_, err = io.Copy(w, file)
		if err != nil {
			l.Error("failed to send file", slog.String("err", err.Error()))
			http.Error(w, "Failed to send file", http.StatusInternalServerError)

			return
		}

		l.Info("File sent successfully", slog.String("filename", filename))
	}
}
