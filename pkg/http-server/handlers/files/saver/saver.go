// TODO: поменять baseDir
// Если файл существует, то ничего не делать
// Добавить логи

package saver

import (
	"context"
	"fmt"
	"io"
	"log/slog"
	"mime/multipart"
	"net/http"
	"os"
	"path/filepath"

	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

const (
	mB10       = 10 << 20
	baseDir    = "./CloudBase"
	fileRights = 0o750
)

type FileSaver interface {
	NewFile(ctx context.Context, userID, filename string, fileSize int64) error
}

func New(log *slog.Logger, fileSaver FileSaver) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.files.saver.New"
		log = log.With(
			slog.String("fn", fn),
			slog.String("requestID", middleware.GetReqID(r.Context())),
		)

		err := r.ParseMultipartForm(mB10)
		if err != nil {
			log.Error("failed to parse multipart form", slog.String("err", err.Error()))
			http.Error(w, "Unable to parse form", http.StatusBadRequest)

			return
		}

		file, handler, err := r.FormFile("file")
		if err != nil {
			log.Error("failed to retrieve file from form", slog.String("err", err.Error()))
			http.Error(w, "Unable to retrieve file", http.StatusBadRequest)

			return
		}
		defer file.Close()

		userID := chi.URLParam(r, "userID")
		if userID == "" {
			log.Error("missing user ID")
			http.Error(w, "User ID is required", http.StatusBadRequest)

			return
		}

		err = saveFileToDisk(userID, handler.Filename, file)
		if err != nil {
			log.Error("failed to save file", slog.String("err", err.Error()))
			http.Error(w, "Failed to save file", http.StatusInternalServerError)

			return
		}

		err = fileSaver.NewFile(r.Context(), userID, handler.Filename, handler.Size)
		if err != nil {
			log.Error("failed to save file info to DB", slog.String("err", err.Error()))
			http.Error(w, "Failed to save file metadata", http.StatusInternalServerError)

			return
		}

		w.WriteHeader(http.StatusCreated)
	}
}

func ensureUserDirectory(userID string) (string, error) {
	userDir := filepath.Join(baseDir, userID)

	if _, err := os.Stat(userDir); os.IsNotExist(err) {
		err := os.MkdirAll(userDir, fileRights)
		if err != nil {
			return "", fmt.Errorf("failed to create user directory: %w", err)
		}
	}

	return userDir, nil
}

func saveFileToDisk(userID, filename string, file multipart.File) error {
	userDir, err := ensureUserDirectory(userID)
	if err != nil {
		return err
	}

	filePath := filepath.Join(userDir, filename)

	dst, err := os.Create(filePath)
	if err != nil {
		return fmt.Errorf("failed to create file: %w", err)
	}
	defer dst.Close()

	_, err = io.Copy(dst, file)
	if err != nil {
		return fmt.Errorf("failed to save file content: %w", err)
	}

	return nil
}
