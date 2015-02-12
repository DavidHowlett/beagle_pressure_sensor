package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(time.Now())
	/*
		ch := make(chan int,1000)
		go sender(ch)
		for i := 0; i < 100000; i++ {
			ch <- i
		}
		close(ch)
	*/
}

func sender(ch chan int) {
	for pressure := range ch {
		fmt.Println(pressure)
	}
	return
}
