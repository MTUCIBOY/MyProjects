package main

import (
	myfind "Day02/myFind/myFindB"
	"os"
)

func main() {
	argsSlice := os.Args[1:]
	for {
		parserInfo, argsRemainder := myfind.ParsingARGS(argsSlice)
		for i := 0; i < len(parserInfo.Filenames()); i++ {
			myfind.ScanDirectory(parserInfo.Flags(), parserInfo.FileExt(), parserInfo.Filenames()[i])
		}
		if argsRemainder == nil {
			break
		}
		argsSlice = argsRemainder
	}
}
