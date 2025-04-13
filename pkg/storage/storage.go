package storage

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
		VALUES ($1, $2, $3)
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
)
