// Пакет postgreSQL нужен для работы сервера с базой данных.
// Используется PGX/V5.
package postgresql

import (
	"context"
	"fmt"
	"log/slog"

	"github.com/jackc/pgx/v5"
)

// Скрипт инициализации таблиц.
const initSchema = `
CREATE TABLE IF NOT EXISTS users (
    id SERIAL PRIMARY KEY,
    password_hash BYTEA NOT NULL,
    email VARCHAR(255) UNIQUE NOT NULL,
    created_at TIMESTAMPTZ DEFAULT NOW()
);

CREATE TABLE IF NOT EXISTS files (
    id SERIAL PRIMARY KEY,
    user_id INT REFERENCES users(id) ON DELETE CASCADE,
    filename VARCHAR(255) NOT NULL,
    size BIGINT NOT NULL,
    upload_time TIMESTAMPTZ DEFAULT NOW()
);
`

// Storage структура для работы с PostgreSQL базой данных.
type Storage struct {
	db *pgx.Conn
}

// New инициализирует структуру Storage.
// Если в БД нет нужных таблиц, создает их.
// В случае ошибки возвращает пустую структуру и ошибку.
func New(ctx context.Context, log *slog.Logger, storagePath string) (Storage, error) {
	const fn = "storage.PSQL.New"
	l := log.With(slog.String("fn", fn))

	dns, err := pgx.ParseConfig(storagePath)
	if err != nil {
		l.Error("error to parse config", "ParseConfig", err)

		return Storage{}, fmt.Errorf("%s: %w", fn, err)
	}

	conn, err := pgx.ConnectConfig(ctx, dns)
	if err != nil {
		l.Error("error to connect to DB", "ConnectConfig", err)

		return Storage{}, fmt.Errorf("%s: %w", fn, err)
	}

	if _, err := conn.Exec(ctx, initSchema); err != nil {
		l.Error("error to create new tables", "Exex", err)

		return Storage{}, fmt.Errorf("%s: %w", fn, err)
	}

	return Storage{db: conn}, nil
}

// Close метод закрывает подкючение к базе данных.
func (s *Storage) Close(ctx context.Context) {
	s.db.Close(ctx)
}
