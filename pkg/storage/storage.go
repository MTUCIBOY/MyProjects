// storage пакет для всех хранилищ. Здесь указаны общие ошибки,
// функции и sql-скрипты
package storage

import (
	"errors"
	"regexp"
)

var (
	ErrFileNotFound      = errors.New("file not found")
	ErrUserNotFound      = errors.New("user not found")
	ErrInvalidParams     = errors.New("invalid params")
	ErrNotEnoughSpace    = errors.New("not enough space")
	ErrFileExists        = errors.New("file exists")
	ErrUserAlreadyExists = errors.New("user already exists")
)

// Скрипты для работы с таблицами.
const (
	InitSchema = `
		CREATE TABLE IF NOT EXISTS users (
				id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
				email VARCHAR(255) UNIQUE NOT NULL,
				password_hash BYTEA NOT NULL,
				space_available BIGINT NOT NULL,
				space_taken BIGINT NOT NULL DEFAULT 0,
				created_at TIMESTAMPTZ DEFAULT NOW()
		);

		CREATE TABLE IF NOT EXISTS files (
				id UUID PRIMARY KEY DEFAULT gen_random_uuid(),
				user_id UUID REFERENCES users(id) ON DELETE CASCADE,
				filename VARCHAR(255) NOT NULL,
				size BIGINT NOT NULL,
				upload_time TIMESTAMPTZ DEFAULT NOW()
		);
		`
	NewUserSchema = `
		INSERT INTO users (email, password_hash, space_available)
		VALUES ($1, $2, $3)
		`

	NewFileSchema = `
		INSERT INTO files (user_id, filename, size)
		VALUES ($1, $2, $3);
	`

	AddSpaceTakenSchema = `
		UPDATE users 
		SET space_taken  = space_taken + $2
		WHERE id = $1;
	`

	SubSpaceTakenSchema = `
		UPDATE users 
		SET space_taken  = space_taken - $2
		WHERE id = $1;
	`

	DeleteUserSchema = `
		DELETE FROM users
		WHERE id = $1	
	`

	DeleteFileSchema = `
		DELETE FROM files
		WHERE user_id = $1 AND filename = $2	
	`

	GetUserIDSchema = `
		SELECT id FROM users
		WHERE email = $1
	`

	CheckSpaceSchema = `
		SELECT (space_available >= space_taken + $1) FROM users
		WHERE id = $2
	`

	CheckFileSchema = `
		SELECT EXISTS (
			SELECT 1
			FROM files
			WHERE user_id = $1 and filename = $2
		)
	`

	CheckUserSchema = `
		SELECT EXISTS (
			SELECT 1
			FROM users
			WHERE id = $1
		)
	`

	GetFilesizeSchema = `
		SELECT size
		FROM files f 
		WHERE user_id = $1 AND filename = $2
	`

	GetAllFilesSchema = `
		SELECT filename
		FROM files
		WHERE user_id = $1
	`

	// #nosec G101
	GetUserPasswordHashSchema = `
		SELECT password_hash
		FROM users
		WHERE id = $1
	`
)

// ValidateEmail функция для валидации почты.
func ValidateEmail(email string) bool {
	const emailRegex = `^[a-zA-Z0-9._%+\-]+@[a-zA-Z0-9.\-]+\.[a-zA-Z]{2,}$`
	re := regexp.MustCompile(emailRegex)

	return re.MatchString(email)
}

// ValidUserParams функция для валидации параметров при регестрации пользователя.
func ValidUserParams(email, password string, spaceAvailable int64) bool {
	if !ValidateEmail(email) || password == "" || spaceAvailable < 1 {
		return false
	}

	return true
}
