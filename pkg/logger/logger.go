// Пакет logger нужен для работы логгера в проекте.
package logger

import (
	"log/slog"
	"os"
)

// Константы уровня окружения.
const (
	envLocal = "local"
	envDev   = "dev"
	envProd  = "prod"
)

// SetupLogger функция создания логгера с нужным окружением.
// Для env=local Level=Debug.
// Для env=dev Level=Debug.
// Для env=prod Level=Info.
func SetupLogger(env string) *slog.Logger {
	var log *slog.Logger

	switch env {
	case envLocal:
		log = slog.New(
			slog.NewTextHandler(os.Stdout, &slog.HandlerOptions{Level: slog.LevelDebug}),
		)
	case envDev:
		log = slog.New(
			slog.NewJSONHandler(os.Stdout, &slog.HandlerOptions{Level: slog.LevelDebug}),
		)
	case envProd:
		log = slog.New(
			slog.NewJSONHandler(os.Stdout, &slog.HandlerOptions{Level: slog.LevelInfo}),
		)
	}

	return log
}
