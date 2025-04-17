package files

import "errors"

const BaseDir = "./CloudBase"

var (
	ErrMissingUserID         = errors.New("missing userID")
	ErrMissingUserIDFilename = errors.New("missing userID or filename")
)
