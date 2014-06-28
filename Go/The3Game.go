package main

import (
	"fmt"
	"strconv"
	"strings"
)

func skipper(skip_num int, from int, end int) {
	n := next(skip_num)
	for i := from; i < end; i++ {
		fmt.Printf("num : %d > %d\n", i, n())
	}
}

func next(skip_num int) func() int {
	num := 1
	return func() int {
		num++
		count := num
		for strings.Contains(strconv.Itoa(count), strconv.Itoa(skip_num)) || (count%skip_num) == 0 {
			count++
		}
		return count
	}
}

func main() {
	fmt.Print("=== test 3 game ===\n")
	skipper(3, 1, 10)
	fmt.Print("=== test 4 game ===\n")
	skipper(4, 1, 50)
}
