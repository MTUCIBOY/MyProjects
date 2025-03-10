package main

import (
	"Day06/source/website"
)

func main() {
	s := website.NewServer("8888", "admin")
	s.Run()
}
