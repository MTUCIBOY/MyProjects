package main

import (
	mywc "Day02/myWc/myWcB"
	"fmt"
	"os"
	"sync"
)

func main() {
	flag, filenames, err := mywc.ParserARGS(os.Args)
	if err != nil {
		fmt.Println(err)
		return
	}

	function := mywc.ChooseFunc(flag)
	var wg sync.WaitGroup
	for _, filename := range filenames {
		wg.Add(1)
		go function(filename, &wg)
	}
	wg.Wait()
}
