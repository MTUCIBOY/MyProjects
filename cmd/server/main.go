package main

import (
	"fmt"

	"github.com/MTUCIBOY/MyProject/VKR/pkg/config"
)

func main() {
	cfg := config.MustLoad()
	fmt.Println(cfg)
}
