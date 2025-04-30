package main

import (
	"context"
	"log/slog"
	"net/http"
	"os"
	"os/signal"
	"syscall"
	"time"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/config"
	filedeleter "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/fileDeleter"
	infogeter "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/infoGeter"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/saver"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/sender"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/login"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/registration"
	userdeleter "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/userDeleter"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/middleware/auth"
	httpheaders "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/middleware/http-headers"
	sanitizefilename "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/middleware/sanitizeFilename"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/logger"
	postgresql "github.com/MTUCIBOY/MyProject/VKR/pkg/storage/postgreSQL"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
	"github.com/go-chi/httprate"
	"github.com/go-chi/jwtauth/v5"
)

func main() {
	cfg := config.MustLoad()
	log := logger.SetupLogger(cfg.Env)
	ctx := context.Background()

	log.Info("Start app", slog.Any("config", cfg))

	db := initDB(ctx, log)
	defer db.Close(ctx)

	router := initRouter(log, db, cfg)

	initServer(log, router, cfg)
}

func initDB(ctx context.Context, log *slog.Logger) *postgresql.Storage {
	log.Info("Start DB")

	db, err := postgresql.New(ctx, log, os.Getenv("STORAGE_DSN"))
	if err != nil {
		panic(err)
	}

	return &db
}

func initRouter(log *slog.Logger, db *postgresql.Storage, cfg *config.Config) *chi.Mux {
	log.Info("Start router")

	router := chi.NewRouter()
	router.Use(
		middleware.RequestID,
		middleware.Logger,
		middleware.Recoverer,
		httpheaders.SetHeadersMiddleware,
		httprate.LimitByIP(cfg.LimitByIP, time.Minute),
		httprate.LimitAll(cfg.LimitAll, time.Minute),
	)

	router.Group(func(r chi.Router) {
		r.Use(jwtauth.Verifier(auth.TokenAuth))
		r.Use(auth.CompareUUIDMiddleware)

		r.Group(func(r chi.Router) {
			r.Use(sanitizefilename.CheckFilenameMiddleware)

			r.Get("/{userID}/{filename}", sender.New(log, db))
			r.Delete("/{userID}/{filename}", filedeleter.New(log, db))
		})

		r.Get("/{userID}", infogeter.New(log, db))

		r.Post("/{userID}", saver.New(log, db))

		r.Delete("/{userID}", userdeleter.New(log, db))
	})

	router.Post("/login", login.New(log, db, cfg.TokenTTL))
	router.Post("/registration", registration.New(log, db))

	return router
}

func initServer(log *slog.Logger, router *chi.Mux, cfg *config.Config) {
	log.Info("Start server", slog.Any("cfg", cfg.HTTPServer))
	srv := &http.Server{
		Addr:         cfg.Address,
		Handler:      router,
		ReadTimeout:  cfg.Timeout,
		WriteTimeout: cfg.Timeout,
		IdleTimeout:  cfg.IdleTimeout,
	}

	gracefulShutdown(log, srv)

	err := srv.ListenAndServeTLS(os.Getenv("CERT_PATH"), os.Getenv("KEY_PATH"))
	if err != nil {
		log.Warn("error from ListenAndServeTSL", slog.String("err", err.Error()))
	}

	log.Info("Server stoped")
}

func gracefulShutdown(log *slog.Logger, server *http.Server) {
	go func() {
		c := make(chan os.Signal, 1)
		signal.Notify(c, syscall.SIGINT, syscall.SIGTERM)
		<-c

		log.Info("Received shutdown signal, gracefully shutting down...")

		if err := server.Shutdown(context.TODO()); err != nil {
			log.Warn("failed to shutdown server", slog.String("err", err.Error()))
		}
	}()
}
