package main

import (
	"context"
	"log/slog"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/config"
	"github.com/MTUCIBOY/MyProject/VKR/pkg/logger"
	postgresql "github.com/MTUCIBOY/MyProject/VKR/pkg/storage/postgreSQL"
)

func main() {
	cfg := config.MustLoad()
	log := logger.SetupLogger(cfg.Env)
	ctx := context.Background()

	log.Info("Config data",
		slog.String("env", cfg.Env),
		slog.String("address", cfg.Address),
		slog.String("StorageDNS", cfg.StorageDNS),
	)

	log.Info("Start DB")

	db, err := postgresql.New(ctx, log, cfg.StorageDNS)
	if err != nil {
		panic(err)
	}
	defer db.Close(ctx)

	log.Info("Start DB is success")
}
