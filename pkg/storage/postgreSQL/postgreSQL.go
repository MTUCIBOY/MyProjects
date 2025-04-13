// Пакет postgreSQL нужен для работы сервера с базой данных.
// Используется PGX/V5.
package postgresql

import (
	"context"
	"fmt"
	"log/slog"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/storage"
	"github.com/jackc/pgx/v5"
	"golang.org/x/crypto/bcrypt"
)

// Storage структура для работы с PostgreSQL базой данных.
type Storage struct {
	db  *pgx.Conn
	log *slog.Logger
}

// New инициализирует структуру Storage.
// Если в БД нет нужных таблиц, создает их.
// В случае ошибки возвращает пустую структуру и ошибку.
func New(ctx context.Context, log *slog.Logger, storagePath string) (Storage, error) {
	const fn = "postgresql.New"
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

	if _, err := conn.Exec(ctx, storage.InitSchema); err != nil {
		l.Error("error to create new tables", "Exex", err)

		return Storage{}, fmt.Errorf("%s: %w", fn, err)
	}

	l.Info("New storage was created")

	return Storage{db: conn, log: log}, nil
}

// Close метод закрывает подкючение к базе данных.
func (s *Storage) Close(ctx context.Context) {
	const fn = "postgresql.storage.Close"

	if err := s.db.Close(ctx); err != nil {
		s.log.Error("error to close DB", fn, err)
	}

	s.log.Info("Connection to DB is closed")
}

// NewUser метод для сохранения нового пользователя в БД.
// spaceAvaible пишется в мегабайтах.
func (s *Storage) NewUser(ctx context.Context, email, password string, spaceAvaible int64) error {
	const fn = "postgresql.storage.NewUser"
	log := s.log.With("fn", fn, "email", email)

	passHash, err := bcrypt.GenerateFromPassword([]byte(password), bcrypt.DefaultCost)
	if err != nil {
		log.Error("fail to generate hash from password", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	_, err = s.db.Exec(ctx, storage.NewUserSchema, email, passHash, spaceAvaible)
	if err != nil {
		log.Error("fail to insert new user to table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	log.Info("New user is saved id DB")

	return nil
}

// NewFile метод сохранения информации о файле в БД.
func (s *Storage) NewFile(ctx context.Context, userID, filename string) error {
	const fn = "postgresql.storage.NewFile"
	log := s.log.With("fn", fn, "id", userID)

	_, err := s.db.Exec(ctx, storage.NewFileSchema, userID, filename)
	if err != nil {
		log.Error("fail to insert new file to table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	log.Info("New file is saved in DB")

	return nil
}

// DeleteFile метод для удаления информации о файле из БД.
func (s *Storage) DeleteFile(ctx context.Context, userID, filename string) error {
	const fn = "postgresql.storage.DeleteFile"
	log := s.log.With("fn", fn, "id", userID)

	_, err := s.db.Exec(ctx, storage.DeleteFileSchema, userID, filename)
	if err != nil {
		log.Error("fail to delete file to table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	log.Info("File is deleted from DB")

	return nil
}

// DeleteUser метод для удаления информации о пользователе из БД.
func (s *Storage) DeleteUser(ctx context.Context, userID string) error {
	const fn = "postgresql.storage.DeleteUser"
	log := s.log.With("fn", fn, "id", userID)

	_, err := s.db.Exec(ctx, storage.DeleteUserSchema, userID)
	if err != nil {
		log.Error("fail to delete user to table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	log.Info("User is deleted from DB")

	return nil
}

// User метод для получения UUID пользователя из его почты.
func (s *Storage) UserID(ctx context.Context, email string) (string, error) {
	const fn = "postgresql.storage.UserID"
	log := s.log.With("fn", fn, "email", email)

	var userID string
	if err := s.db.QueryRow(ctx, storage.GetUserIDSchema, email).Scan(&userID); err != nil {
		log.Error("fail to get userID from table", slog.String("err", err.Error()))

		return "", fmt.Errorf("%s: %w", fn, err)
	}

	return userID, nil
}
