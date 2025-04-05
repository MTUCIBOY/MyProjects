package postgresql

import (
	"context"
	"fmt"
	"log/slog"

	"github.com/jackc/pgx/v5"
)

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

type Storage struct {
	db *pgx.Conn
}

func New(log *slog.Logger, storagePath string) (Storage, error) {
	const fn = "storage.PSQL.New"
	l := log.With(slog.String("fn", fn))

	dns, err := pgx.ParseConfig(storagePath)
	if err != nil {
		l.Error("error to parse config", "ParseConfig", err)

		return Storage{}, fmt.Errorf("%s: %w", fn, err)
	}

	conn, err := pgx.ConnectConfig(context.Background(), dns)
	if err != nil {
		l.Error("error to connect to DB", "ConnectConfig", err)

		return Storage{}, fmt.Errorf("%s: %w", fn, err)
	}

	if _, err := conn.Exec(context.Background(), initSchema); err != nil {
		l.Error("error to create new tables", "Exex", err)

		return Storage{}, fmt.Errorf("%s: %w", fn, err)
	}

	return Storage{db: conn}, nil
}

func (s *Storage) Close() {
	s.db.Close(context.Background())
}
