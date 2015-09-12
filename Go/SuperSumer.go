package main

import (
	"fmt"
	"math/rand"
	"time"
)

var globalVar int = 0

func doSum(ch chan int, start int, end int) {
	// do something heavy job

	globalVar = start

	r := time.Duration(rand.Int63n(3))
	time.Sleep(r * time.Second)
	b := end * (end + 1) / 2
	a := start * (start + 1) / 2
	ch <- int(b - a)
}

func sum(end int, worker int) (sum int) {
	gap := end / worker
	ch := make(chan int)
	for i := 0; i < worker; i++ {
		go doSum(ch, (gap * i), gap*(i+1))
	}
	sum = 0
	for i := 0; i < worker; i++ {
		sum += <-ch
	}
	return
}

func main() {
	fmt.Printf(" sum = %d\n", sum(10000, 1))
	fmt.Printf(" sum = %d\n", sum(10000, 2))
	fmt.Printf(" sum = %d\n", sum(10000, 10))
	// fmt.Printf(" sum = %d\n", sum(10000, 100))
}
