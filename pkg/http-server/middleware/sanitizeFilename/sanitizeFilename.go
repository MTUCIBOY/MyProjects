package sanitizefilename

import (
	"log/slog"
	"net/http"
	"path/filepath"
	"strings"

	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

func CheckFilenameMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		const fn = "middleware.sanitizeFilename.sanitizeFilenameMiddleware"
		log := slog.With(
			slog.String("fn", fn),
			slog.String("request ID", middleware.GetReqID(r.Context())),
		)

		log.Info(chi.URLParam(r, "filename"))

		cleanPath := filepath.Clean(chi.URLParam(r, "filename"))

		log.Info(cleanPath)

		if filepath.IsAbs(cleanPath) || strings.HasPrefix(cleanPath, "..") {
			log.Error("Invalid filename")
			http.Error(w, "Invalid filename", http.StatusBadRequest)
		}

		next.ServeHTTP(w, r)
	})
}
