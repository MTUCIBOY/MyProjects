// Saver пакет для хендлера save.
// Нужен, чтобы сохранять файлы на облаке.
package saver

import (
	"context"
	"errors"
	"fmt"
	"io"
	"log/slog"
	"mime/multipart"
	"net/http"
	"os"
	"path/filepath"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/storage"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

const (
	mB10       = 10 << 20
	fileRights = 0o750
)

// FileSaver интерфейс для работы с БД. Нужная абстракция, если БД будет меняться.
type fileSaver interface {
	NewFile(ctx context.Context, userID, filename string, fileSize int64) error
}

// New функция для создания хендлера save.
func New(log *slog.Logger, fileSaver fileSaver) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		const fn = "handlers.files.saver.New"
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

		err := r.ParseMultipartForm(mB10)
		if err != nil {
			log.Error("failed to parse multipart form", slog.String("err", err.Error()))
			http.Error(w, "Unable to parse form", http.StatusBadRequest)

			return
		}
		defer removeMultipartFiles(log, r)

		file, handler, err := r.FormFile("file")
		if err != nil {
			log.Error("failed to retrieve file from form", slog.String("err", err.Error()))
			http.Error(w, "Unable to retrieve file", http.StatusBadRequest)

			return
		}
		defer file.Close()

		err = fileSaver.NewFile(r.Context(), userID, handler.Filename, handler.Size)
		if err != nil {
			checkErrFromDB(err, log, w)

			return
		}

		err = saveFileToDisk(userID, handler.Filename, file)
		if err != nil {
			log.Error("failed to save file on disk", slog.String("err", err.Error()))
			http.Error(w, "Failed to save file", http.StatusInternalServerError)

			return
		}

		log.Info("File is saved")

		w.WriteHeader(http.StatusCreated)
	}
}

// ensureUserDirectory функция для проверки и создания папки пользователя на облаке.
func ensureUserDirectory(userID string) (string, error) {
	userDir := filepath.Join(files.BaseDir, userID)
	if _, err := os.Stat(userDir); os.IsNotExist(err) {
		err := os.MkdirAll(userDir, fileRights)
		if err != nil {
			return "", fmt.Errorf("failed to create user directory: %w", err)
		}
	}

	return userDir, nil
}

// saveFileToDisk функция сохранения файла на облаке.
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

// removeMultipartFiles фунция удаления временных файлов из папки /tmp.
func removeMultipartFiles(log *slog.Logger, r *http.Request) {
	err := r.MultipartForm.RemoveAll()
	if err != nil {
		log.Warn(
			"err when deleted multipart files",
			slog.String("err", err.Error()),
		)
	}
}

// checkErrFromDB процедура для проверки ошибки из ДБ.
// Эта часть кода была вынесена в отдельную процедуру из-за своих размеров.
func checkErrFromDB(err error, log *slog.Logger, w http.ResponseWriter) {
	if errors.Is(err, storage.ErrFileExists) {
		log.Error(err.Error())
		http.Error(w, "Failed to save file, file exists", http.StatusBadRequest)

		return
	}

	if errors.Is(err, storage.ErrNotEnoughSpace) {
		log.Error(err.Error())
		http.Error(w, "Failed to save file, not enough space", http.StatusBadRequest)

		return
	}

	if errors.Is(err, storage.ErrUserNotFound) {
		log.Error(err.Error())
		http.Error(w, "Failed to save file, user not found", http.StatusBadRequest)

		return
	}

	http.Error(w, "Failed to save file metadata", http.StatusInternalServerError)
}
