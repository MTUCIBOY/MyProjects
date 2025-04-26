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

const AESbytes = 32

func EncryptData(data, key []byte) ([]byte, error) {
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

	nonce := make([]byte, aesGCM.NonceSize())
	if _, err := io.ReadFull(rand.Reader, nonce); err != nil {
		log.Error("failed to read", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	cipherText := aesGCM.Seal(nonce, nonce, data, nil)

	return cipherText, nil
}

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

	nonce, data := data[:nonceSize], data[nonceSize:]

	decryptData, err := aesGCM.Open(nil, nonce, data, nil)
	if err != nil {
		log.Error("failed to open arsGCM", slog.String("err", err.Error()))

		return nil, fmt.Errorf("%s: %w", fn, err)
	}

	return decryptData, nil
}
