// files общий пакет для работы с файлами на сервере.
// Включает в себя общие ошибки и константы.
package files

import "errors"

const BaseDir = "./CloudBase"

var (
	ErrMissingUserID         = errors.New("missing userID")
	ErrMissingUserIDFilename = errors.New("missing userID or filename")
)
