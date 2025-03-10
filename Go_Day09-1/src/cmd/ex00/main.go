package main

import (
	"Day09/pkg"
	"fmt"
)

func main() {
	// s := []int{4, 3, 2, 1, 5, 7, 8, 10}
	s2 := []int{}
	// ch := pkg.SleepSort(s)
	ch2 := pkg.SleepSort(s2)

	// for res := range ch {
	// 	fmt.Println(res)
	// }
	fmt.Println(<-ch2)
}
