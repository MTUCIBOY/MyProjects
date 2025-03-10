package main

import (
	"Day09/pkg"
	"fmt"
)

func main() {
	chInt := make(chan any)
	chFloat := make(chan any)
	chString := make(chan any)

	go func(ch chan any) {
		slice := []int{1, 2, 3, 4, 5, 6, 7, 8}
		for _, val := range slice {
			ch <- val
		}
		close(ch)
	}(chInt)
	go func(ch chan any) {
		slice := []float64{3.14, 2.71, 10.1, 13.2}
		for _, val := range slice {
			ch <- val
		}
		close(ch)
	}(chFloat)
	go func(ch chan any) {
		slice := []string{
			"123",
			"Hello",
			"Bebra",
			"World",
		}
		for _, val := range slice {
			ch <- val
		}
		close(ch)
	}(chString)

	multiCh := pkg.Multiplex(nil, chFloat, chString)

	for val := range multiCh {
		fmt.Println(val)
	}
}
