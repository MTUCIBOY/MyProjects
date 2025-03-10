package main

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	stdinSlice := make([]string, 0, 5)
	for scanner.Scan() {
		stdinSlice = append(stdinSlice, scanner.Text())
	}
	arguments := append(os.Args[2:], stdinSlice...)
	cmd := exec.Command(os.Args[1], arguments...)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr

	if err := cmd.Run(); err != nil {
		fmt.Fprintf(os.Stderr, "Ошибка выполнения команды: %v\n", err)
		return
	}
}
