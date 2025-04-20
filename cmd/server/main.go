package main

import (
	"context"
	"log/slog"
	"net/http"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/config"
	filedeleter "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/fileDeleter"
	infogeter "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/infoGeter"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/saver"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/files/sender"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/registration"
	userdeleter "github.com/MTUCIBOY/MyProject/VKR/pkg/http-server/handlers/users/userDeleter"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/logger"
	postgresql "github.com/MTUCIBOY/MyProject/VKR/pkg/storage/postgreSQL"
	"github.com/go-chi/chi/v5"
	"github.com/go-chi/chi/v5/middleware"
)

func main() {
	cfg := config.MustLoad()
	log := logger.SetupLogger(cfg.Env)
	ctx := context.Background()

	log.Info("Start app", slog.Any("config", cfg))

	log.Info("Start DB")

	db, err := postgresql.New(ctx, log, cfg.StorageDSN)
	if err != nil {
		panic(err)
	}
	defer db.Close(ctx)

	log.Info("Start DB is success")

	log.Info("Start router")

	router := chi.NewRouter()
	router.Use(
		middleware.RequestID,
		middleware.Logger,
		middleware.Recoverer,
	)

	router.Get("/{userID}", infogeter.New(log, &db))
	router.Get("/{userID}/{filename}", sender.New(log, &db))

	router.Post("/{userID}", saver.New(log, &db))
	router.Post("/registration", registration.New(log, &db))

	router.Delete("/{userID}/{filename}", filedeleter.New(log, &db))
	router.Delete("/{userID}", userdeleter.New(log, &db))

	log.Info("Start server", slog.Any("cfg", cfg))
	srv := &http.Server{
		Addr:         cfg.Address,
		Handler:      router,
		ReadTimeout:  cfg.Timeout,
		WriteTimeout: cfg.Timeout,
		IdleTimeout:  cfg.IdleTimeout,
	}

	if err := srv.ListenAndServe(); err != nil {
		log.Error("failed to start server", slog.String("err", err.Error()))
	}

	log.Error("server stopped")
}
