package sanitizefilename

import (
	"log/slog"
	"net/http"
	"path/filepath"
	"regexp"
	"strings"

	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

const maxFilenameLen = 260

func CheckFilenameMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		const fn = "middleware.sanitizeFilename.sanitizeFilenameMiddleware"
		log := slog.With(
			slog.String("fn", fn),
			slog.String("request ID", middleware.GetReqID(r.Context())),
		)

		cleanPath := filepath.Clean(chi.URLParam(r, "filename"))

		if !IsValidFileName(cleanPath) {
			log.Error("Invalid filename")
			http.Error(w, "Invalid filename", http.StatusBadRequest)

			return
		}

		if filepath.IsAbs(cleanPath) || strings.HasPrefix(cleanPath, "..") {
			log.Error("Invalid filename")
			http.Error(w, "Invalid filename", http.StatusBadRequest)

			return
		}

		next.ServeHTTP(w, r)
	})
}

func IsValidFileName(filename string) bool {
	if len(filename) > maxFilenameLen {
		return false
	}

	if len(filename) == 0 {
		return false
	}

	if strings.HasPrefix(filename, ".") {
		return false
	}

	// Разрешаем только буквы, цифры, дефисы, подчёркивания и точки
	match, _ := regexp.MatchString(`^[a-zA-Z0-9._-]+$`, filename)

	return match
}
