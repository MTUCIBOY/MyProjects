// filecrypt пакет для шифрования/дешифрования файлов облака.
// Использует алгоритм AES.
package filecrypt

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"errors"
	"fmt"
	"io"
	"log/slog"
)

var (
	ErrInvalidData = errors.New("invalid data")
	ErrInvalidKey  = errors.New("invalid key")
)

// EncryptData шифрует данные, возвращает тоже количество байт,
// сколько и пришло. Ключ должен быть строго 32 байта, иначе будет ошибка!
// В случае ошибки возвращает nil + ошибку.
func EncryptData(data, key []byte) ([]byte, error) {
	const fn = "fileCrypt.EncryptFile"
	log := slog.With(slog.String("fn", fn))

	// Создаем новый шифр на основе ключа
	block, err := aes.NewCipher(key)
	if err != nil {
		log.Error("failed to create new block", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	// Ставим режим работы шифра GCM - Galois/Counter Mode.
	// Это блочный шифр с симметричным ключом
	aesGCM, err := cipher.NewGCM(block)
	if err != nil {
		log.Error("failed to create new GCM", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	// nonce (число, используемое один раз). Обеспечивает уникальность
	// шифрования
	nonce := make([]byte, aesGCM.NonceSize())
	// Здесь заполняем nonce случайными числами
	if _, err := io.ReadFull(rand.Reader, nonce); err != nil {
		log.Error("failed to read", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	// Шифруем данные
	cipherText := aesGCM.Seal(nonce, nonce, data, nil)

	return cipherText, nil
}

// DecryptData дешифрует данные, возвращает тоже количество байт,
// сколько и пришло. Ключ должен быть строго 32 байта, иначе будет ошибка!
// В случае ошибки возвращает nil + ошибку.
func DecryptData(data, key []byte) ([]byte, error) {
	const fn = "fileCrypt.EncryptFile"
	log := slog.With(slog.String("fn", fn))

	block, err := aes.NewCipher(key)
	if err != nil {
		log.Error("failed to create new block", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	aesGCM, err := cipher.NewGCM(block)
	if err != nil {
		log.Error("failed to create new GCM", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	nonceSize := aesGCM.NonceSize()
	if len(data) < nonceSize {
		log.Error("data len less then nonce size")

		return nil, fmt.Errorf("%s: %w", fn, ErrInvalidData)
	}

	// Берем nonce и шифрованые данные из блока
	nonce, data := data[:nonceSize], data[nonceSize:]

	// Дешифруем данные
	decryptData, err := aesGCM.Open(nil, nonce, data, nil)
	if err != nil {
		log.Error("failed to open arsGCM", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	return decryptData, nil
}
