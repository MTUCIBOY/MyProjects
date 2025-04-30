// sender пакет для хендлера send.
// Нужен для отправки файлов с облака пользователю.
package sender

import (
	"context"
	"encoding/base64"
	"errors"
	"fmt"
	"log/slog"
	"net/http"
	"os"
	"path/filepath"

	filecrypt "github.com/MTUCIBOY/MyProject/VKR/pkg/fileCrypt"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/storage"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

// FileSender интерфейс для работы с БД. Нужная абстракция, если БД будет меняться.
type fileSender interface {
	IsFileExist(ctx context.Context, userID, filename string) (bool, error)
}

// New функция для создания хендлера send.
func New(log *slog.Logger, fileSender fileSender) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.files.sender.New"
		log := log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		userID := chi.URLParam(r, "userID")
		filename := chi.URLParam(r, "filename")

		if userID == "" || filename == "" {
			log.Error(files.ErrMissingUserIDFilename.Error())
			http.Error(w, "User ID and filename are required", http.StatusBadRequest)

			return
		}

		exists, err := fileSender.IsFileExist(r.Context(), userID, filename)
		if err != nil {
			if errors.Is(err, storage.ErrUserNotFound) {
				log.Error(storage.ErrUserNotFound.Error())
				http.Error(w, "User not found", http.StatusBadRequest)

				return
			}

			log.Error("failed to check file existence", slog.String("err", err.Error()))
			http.Error(w, "Failed to check file existence", http.StatusInternalServerError)

			return
		}

		if !exists {
			log.Error("file not found", slog.String("filename", filename))
			http.Error(w, "File not found", http.StatusNotFound)

			return
		}

		w.Header().Set("Content-Type", "application/octet-stream")
		w.Header().Set("Content-Disposition", fmt.Sprintf(`attachment; filename="%s"`, filename))

		filePath := filepath.Join(files.BaseDir, userID, filename)

		if err := sendFile(log, filePath, w); err != nil {
			return
		}

		log.Info("File sent successfully", slog.String("filename", filename))
	}
}

// sendFile функция для отправки файла пользователю.
func sendFile(log *slog.Logger, filePath string, w http.ResponseWriter) error {
	file, err := os.ReadFile(filePath)
	if err != nil {
		log.Error("failed to open file", slog.String("err", err.Error()))
		http.Error(w, "Failed to open file", http.StatusInternalServerError)

		return fmt.Errorf("failed to open file: %w", err)
	}

	key, err := base64.StdEncoding.DecodeString(os.Getenv("FILE_ENCRYPTION_KEY"))
	if err != nil {
		log.Error("failed to decode string", slog.String("err", err.Error()))
		http.Error(w, "Failed to decrypt file", http.StatusInternalServerError)

		return fmt.Errorf("failed to decrypt file: %w", err)
	}

	decryptData, err := filecrypt.DecryptData(file, key)
	if err != nil {
		log.Error("failed to decrypt file", slog.String("err", err.Error()))
		http.Error(w, "Failed to decrypt file", http.StatusInternalServerError)

		return fmt.Errorf("failed to decrypt file: %w", err)
	}

	_, err = w.Write(decryptData)
	if err != nil {
		log.Error("failed to send file", slog.String("err", err.Error()))
		http.Error(w, "Failed to send file", http.StatusInternalServerError)

		return fmt.Errorf("failed to send file: %w", err)
	}

	return nil
}
