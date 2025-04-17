// Пакет postgreSQL нужен для работы сервера с базой данных.
// Используется PGX/V5.
package postgresql

import (
	"context"
	"errors"
	"fmt"
	"log/slog"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/storage"
	"github.com/jackc/pgx/v5"
	"github.com/jackc/pgx/v5/pgconn"
	"golang.org/x/crypto/bcrypt"
)

const NotUniqueEmail = "23505"

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
// spaceAvaible пишется в байтах.
func (s *Storage) NewUser(ctx context.Context, email, password string, spaceAvaible int64) error {
	const fn = "postgresql.storage.NewUser"
	log := s.log.With("fn", fn, "email", email)

	if spaceAvaible < 1 || !storage.ValidateEmail(email) {
		log.Error(
			"Invalid params",
			slog.Int64("spaceAvaible", spaceAvaible),
			slog.Bool("email validator", storage.ValidateEmail(email)),
		)

		return fmt.Errorf("%s: %w", fn, storage.ErrInvalidParams)
	}

	passHash, err := bcrypt.GenerateFromPassword([]byte(password), bcrypt.DefaultCost)
	if err != nil {
		log.Error("fail to generate hash from password", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	_, err = s.db.Exec(ctx, storage.NewUserSchema, email, passHash, spaceAvaible)
	if err != nil {
		var pgErr *pgconn.PgError
		if errors.As(err, &pgErr) && pgErr.Code == NotUniqueEmail {
			log.Error("User already exist", slog.String("err", err.Error()))

			return fmt.Errorf("%s: %w", fn, storage.ErrNotUniqueEmail)
		}

		log.Error("fail to insert new user to table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	log.Info("New user is saved id DB")

	return nil
}

// NewFile метод сохранения информации о файле в БД.
func (s *Storage) NewFile(ctx context.Context, userID, filename string, fileSize int64) error {
	const fn = "postgresql.storage.NewFile"
	log := s.log.With("fn", fn, "userID", userID)

	isFileExist, err := s.IsFileExist(ctx, userID, filename)
	if err != nil {
		log.Error("err in func isFileExist", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	if isFileExist {
		log.Error("fail save file, file exists")

		return fmt.Errorf("%s: %w", fn, storage.ErrFileExists)
	}

	err = s.isHasSpace(ctx, userID, fileSize)
	if err != nil {
		log.Error("err in func isHasSpace", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	_, err = s.db.Exec(ctx, storage.AddSpaceTakenSchema, userID, fileSize)
	if err != nil {
		log.Error("fail to change space_taken in table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	_, err = s.db.Exec(ctx, storage.NewFileSchema, userID, filename, fileSize)
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
	log := s.log.With("fn", fn, "userID", userID, "filename", filename)

	isFileExist, err := s.IsFileExist(ctx, userID, filename)
	if err != nil {
		log.Error("err in func isFileExist", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	if !isFileExist {
		log.Error(storage.ErrFileNotFound.Error())

		return fmt.Errorf("%s: %w", fn, storage.ErrFileNotFound)
	}

	filesize, err := s.fileSize(ctx, userID, filename)
	if err != nil {
		log.Error("fail to get filesize", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	_, err = s.db.Exec(ctx, storage.SubSpaceTakenSchema, userID, filesize)
	if err != nil {
		log.Error("fail to update space_taken", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	commandTag, err := s.db.Exec(ctx, storage.DeleteFileSchema, userID, filename)
	if err != nil {
		log.Error("fail to delete file to table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	if commandTag.RowsAffected() == 0 {
		log.Error(storage.ErrFileNotFound.Error())

		return fmt.Errorf("%s: %w", fn, storage.ErrFileNotFound)
	}

	log.Info("File is deleted from DB")

	return nil
}

// DeleteUser метод для удаления информации о пользователе из БД.
func (s *Storage) DeleteUser(ctx context.Context, userID string) error {
	const fn = "postgresql.storage.DeleteUser"
	log := s.log.With("fn", fn, "userID", userID)

	commandTag, err := s.db.Exec(ctx, storage.DeleteUserSchema, userID)
	if err != nil {
		log.Error("fail to delete user to table", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	if commandTag.RowsAffected() == 0 {
		log.Error(storage.ErrUserNotFound.Error())

		return fmt.Errorf("%s: %w", fn, storage.ErrUserNotFound)
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

// IsFileExist метод для проверки существования файла.
// Также проверяет существование пользователя.
func (s *Storage) IsFileExist(ctx context.Context, userID, filename string) (bool, error) {
	const fn = "postgresql.storage.isFileExist"
	log := s.log.With("fn", fn, "userID", userID)

	var IsFileExist bool

	isUserExist, err := s.isUserExist(ctx, userID)
	if err != nil {
		log.Error("failed to check user", slog.String("err", err.Error()))

		return IsFileExist, fmt.Errorf("%s: %w", fn, err)
	}

	if !isUserExist {
		log.Error(storage.ErrUserNotFound.Error())

		return IsFileExist, fmt.Errorf("%s: %w", fn, storage.ErrUserNotFound)
	}

	row := s.db.QueryRow(ctx, storage.CheckFileSchema, userID, filename)
	if err := row.Scan(&IsFileExist); err != nil {
		log.Error("fail to check space", slog.String("err", err.Error()))

		return IsFileExist, fmt.Errorf("%s: %w", fn, err)
	}

	return IsFileExist, nil
}

// isHasSpace метод для проверки есть ли свободное место.
func (s *Storage) isHasSpace(ctx context.Context, userID string, fileSize int64) error {
	const fn = "postgresql.storage.isHasSpace"
	log := s.log.With("fn", fn, "userID", userID)

	var IsHasSpace bool

	row := s.db.QueryRow(ctx, storage.CheckSpaceSchema, fileSize, userID)
	if err := row.Scan(&IsHasSpace); err != nil {
		log.Error("fail to check space", slog.String("err", err.Error()))

		return fmt.Errorf("%s: %w", fn, err)
	}

	if !IsHasSpace {
		log.Error("not enough space")

		return fmt.Errorf("%s: %w", fn, storage.ErrNotEnoughSpace)
	}

	return nil
}

// isUserExist метод для проверки существует ли пльзователь.
func (s *Storage) isUserExist(ctx context.Context, userID string) (bool, error) {
	const fn = "postgresql.storage.isUserExist"
	log := s.log.With("fn", fn, "userID", userID)

	var isUserExist bool

	row := s.db.QueryRow(ctx, storage.CheckUserSchema, userID)
	if err := row.Scan(&isUserExist); err != nil {
		log.Error("fail to check user", slog.String("err", err.Error()))

		return isUserExist, fmt.Errorf("%s: %w", fn, err)
	}

	return isUserExist, nil
}

// fileSize метод для получения размера файла.
func (s *Storage) fileSize(ctx context.Context, userID, filename string) (int64, error) {
	const fn = "postgresql.storage.fileSize"
	log := s.log.With(
		slog.String("fn", fn),
		slog.String("userID", userID),
		slog.String("filename", filename),
	)

	var filesize int64

	err := s.db.QueryRow(ctx, storage.GetFilesizeSchema, userID, filename).Scan(&filesize)
	if err != nil {
		log.Error("failed to get file size", slog.String("err", err.Error()))

		return 0, fmt.Errorf("%s: %w", fn, err)
	}

	return filesize, nil
}
