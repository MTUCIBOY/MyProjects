package main

import (
	"Team00/source/server"
)

func main() {
	s := server.NewServer(1337)
	s.Run()
}
