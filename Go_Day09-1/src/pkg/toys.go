package pkg

import (
	"context"
	"io"
	"net/http"
	"sync"
	"time"
)

func SleepSort(nums []int) <-chan int {
	resChan := make(chan int)
	var wg sync.WaitGroup
	wg.Add(len(nums))

	for _, n := range nums {
		go func(sec int) {
			defer wg.Done()
			time.Sleep(time.Second * time.Duration(n))
			resChan <- n
		}(n)
	}

	go func() {
		wg.Wait()
		close(resChan)
	}()

	return resChan
}

func CrawWeb(urls <-chan string, ctx context.Context) <-chan *string {
	result := make(chan *string)
	sem := make(chan struct{}, 8)
	var wg sync.WaitGroup

	go func() {
		defer func() {
			wg.Wait()
			close(result)
		}()

		for {
			select {
			case <-ctx.Done():
				return
			case url, ok := <-urls:
				if !ok {
					return
				}
				sem <- struct{}{}
				wg.Add(1)

				go func(url string) {
					defer func() {
						<-sem
						wg.Done()
					}()

					req, err := http.NewRequestWithContext(ctx, "GET", url, nil)
					if err != nil {
						return
					}

					resp, err := http.DefaultClient.Do(req)
					if err != nil {
						return
					}
					defer resp.Body.Close()

					body, err := io.ReadAll(resp.Body)
					if err != nil {
						return
					}
					res := string(body)

					select {
					case result <- &res:
					case <-ctx.Done():
					}
				}(url)
			}
		}
	}()

	return result
}

func Multiplex(inputCh ...chan any) <-chan any {
	resChan := make(chan any)
	var wg sync.WaitGroup
	wg.Add(len(inputCh))

	for _, ch := range inputCh {
		if ch == nil {
			wg.Done()
			continue
		}

		go func(ch chan any) {
			defer wg.Done()
			for val := range ch {
				resChan <- val
			}
		}(ch)
	}

	go func() {
		wg.Wait()
		close(resChan)
	}()

	return resChan
}
