package main

import (
	"Day01/DB"
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

// Преполагаемое число строк в файле
const lenMap = 100000

func main() {
	if len(os.Args) != 5 {
		log.Fatal("invalid command. Try ./compareFS --old <filename> --new <filename>")
	}
	mARGS := DB.ParserCMD(os.Args)

	var oldFile, newFile map[string]bool

	for key, value := range mARGS {
		switch key {
		case "--old":
			if !strings.Contains(value, ".txt") {
				log.Fatal("--old: file is not .txt")
			}
			oldFile = makeMapFile(value)
		case "--new":
			if !strings.Contains(value, ".txt") {
				log.Fatal("--new: file is not .txt")
			}
			newFile = makeMapFile(value)
		default:
			log.Fatal("invalid command. Try ./compareFS --old <filename> --new <filename>")
		}
	}

	compareTXT(&oldFile, &newFile)
}

func makeMapFile(filename string) map[string]bool {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	result := make(map[string]bool, lenMap)
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		if scanner.Text() != "" {
			result[scanner.Text()] = true
		}
	}
	return result
}

func compareTXT(oldFile, newFile *map[string]bool) {
	countRemoved, countAdded := 0, 0

	for key := range *newFile {
		if !(*oldFile)[key] {
			fmt.Println("ADDED", key)
			countAdded++
		}
	}
	for key := range *oldFile {
		if !(*newFile)[key] {
			fmt.Println("REMOVED", key)
			countRemoved++
		}
	}
	fmt.Println("Added:", countAdded)
	fmt.Println("Removed:", countRemoved)
}
