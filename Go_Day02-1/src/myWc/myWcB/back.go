package mywc

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strings"
	"sync"
)

const (
	flagL = iota + 1
	flagM
	flagW
)

func ParserARGS(args []string) (int, []string, error) {
	if len(args) < 2 {
		return 0, nil, errors.New("invalid command")
	}
	filemames := make([]string, 0, len(args)-1)
	flag := 0
	check := false

	switch args[1] {
	case "-l":
		flag = flagL
	case "-m":
		flag = flagM
	case "-w":
		flag = flagW
	default:
		flag = flagW
		check = true
	}

	if check {
		args = args[1:]
	} else {
		args = args[2:]
	}

	filemames = append(filemames, args...)

	return flag, filemames, nil
}

func ChooseFunc(flag int) func(string, *sync.WaitGroup) {
	switch flag {
	case flagL:
		return CountStr
	case flagM:
		return CountWord
	case flagW:
		return CountByte
	}
	return nil
}

func CountStr(filename string, wg *sync.WaitGroup) {
	defer wg.Done()
	file, err := os.Open(filename)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)

	var result uint
	for scanner.Scan() {
		result++
	}
	if err := scanner.Err(); err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%v\t%v\n", result, filename)
}

func CountByte(filename string, wg *sync.WaitGroup) {
	defer wg.Done()
	file, err := os.ReadFile(filename)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Printf("%v\t%v\n", len(file), filename)
}

func CountWord(filename string, wg *sync.WaitGroup) {
	defer wg.Done()
	file, err := os.Open(filename)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)

	var result int
	for scanner.Scan() {
		result += len(strings.Fields(scanner.Text()))
	}
	if err := scanner.Err(); err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%v\t%v\n", result, filename)
}
