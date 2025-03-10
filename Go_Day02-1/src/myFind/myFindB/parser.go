package myfind

import (
	"fmt"
	"os"
	"strings"
)

const (
	FILE = 1 << iota
	DIRECTORY
	SYMLINKS
	EXT
)

type infoFromARGS struct {
	flags     int
	fileExt   string
	fileNames []string
}

func (i *infoFromARGS) Flags() int {
	return i.flags
}

func (i *infoFromARGS) Filenames() []string {
	return i.fileNames
}

func (i *infoFromARGS) FileExt() string {
	return i.fileExt
}

func ParsingARGS(args []string) (infoFromARGS, []string) {
	var flagArgs = false
	result := infoFromARGS{
		flags:     0,
		fileExt:   "",
		fileNames: make([]string, 0, 1),
	}

	for i := 0; i < len(args); i++ {
		switch args[i] {
		case "-f":
			result.flags = result.flags | FILE
		case "-d":
			result.flags = result.flags | DIRECTORY
		case "-sl":
			result.flags = result.flags | SYMLINKS
		case "-ext":
			result.flags = result.flags | EXT
			result.flags = result.flags | FILE
			if i+1 != len(args) {
				result.fileExt = "." + args[i+1]
				i++
			}
		default:
			result.fileNames = append(result.fileNames, args[i])
			if i+1 != len(args) && args[i+1][0] == '-' {
				args = args[i+1:]
				i = len(args) //Выход из цикла
				flagArgs = true
			}
		}
	}

	if !flagArgs {
		args = nil
	}
	if result.flags == 0 {
		result.flags = FILE | DIRECTORY | SYMLINKS
	}

	return result, args
}

func ScanDirectory(flags int, ext string, dirName string) {
	files, err := os.ReadDir(dirName)
	if err != nil && !os.IsPermission(err) {
		fmt.Println(err)
		return
	}
	if flags&DIRECTORY != 0 {
		fmt.Println(dirName)
	}
	for _, file := range files {
		filepath := dirName + file.Name()
		if file.IsDir() { // Обработка директори
			ScanDirectory(flags, ext, filepath+"/")
		} else { // Обработка симлинков
			filelink, err := os.Lstat(filepath)
			if err != nil {
				continue
			}
			if flags&SYMLINKS != 0 && filelink.Mode()&os.ModeSymlink != 0 {
				fmt.Print(filepath, " -> ")
				targetFilelink, err := os.Readlink(filepath)
				if err != nil {
					fmt.Println("[broken]")
					continue
				}
				_, err = os.Stat(dirName + targetFilelink)
				if err != nil {
					fmt.Println("[broken]")
				} else {
					fmt.Println(targetFilelink)
				}
			} else if flags&FILE != 0 { // Обработка файла
				check, err := os.Open(filepath)
				if err == nil {
					if flags&EXT == 0 || (flags&EXT != 0 && strings.Contains(filepath, ext)) {
						fmt.Println(filepath)
					}
				}
				defer check.Close()
			}
		}
	}
}
