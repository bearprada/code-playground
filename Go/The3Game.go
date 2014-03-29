package main

import (
	"fmt"
	"strconv"
	"strings"
)

func skipper(skip_num int, from int, end int) {
	for i := from; i < end; i++ {
		fmt.Printf("num : %d > %d\n", i, next(i, skip_num))
	}
}

func next(num int, skip_num int) int {
	return find_next(num, skip_num)
}

func find_next(num int, skip_num int) int {
	count := num + 1
	for strings.Contains(strconv.Itoa(count), strconv.Itoa(skip_num)) || (count%skip_num) == 0 {
		count++
	}
	return count
}

func main() {
	fmt.Print("=== test 3 game ===\n")
	skipper(3, 1, 50)
	fmt.Print("=== test 4 game ===\n")
	skipper(4, 1, 50)
}
