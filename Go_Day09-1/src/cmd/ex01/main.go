package main

import (
	"Day09/pkg"
	"context"
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	ctx, cancle := context.WithCancel(context.Background())
	urls := make(chan string)

	go func() {
		sigChan := make(chan os.Signal, 1)
		signal.Notify(sigChan, syscall.SIGINT, syscall.SIGTERM)
		<-sigChan
		cancle()
	}()

	go func() {
		defer close(urls)
		urlsToCrawl := []string{
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://golang.org",
			"https://google.com",
			"https://ya.ru",
		}
		for _, url := range urlsToCrawl {
			select {
			case urls <- url:
			case <-ctx.Done():
				return
			}
		}
	}()

	results := pkg.CrawWeb(urls, ctx)
	for res := range results {
		fmt.Println(res)
	}
}
