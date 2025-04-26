// files общий пакет для работы с файлами на сервере.
// Включает в себя общие ошибки и константы.
package files

import (
	"errors"
	"log"
	"os"
)

var BaseDir string

func init() {
	BaseDir = os.Getenv("BASE_PATH")

	if BaseDir == "" {
		log.Fatal("BASE_PATH is not set")
	}
}

var (
	ErrMissingUserID         = errors.New("missing userID")
	ErrMissingUserIDFilename = errors.New("missing userID or filename")
)
