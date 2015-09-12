package main

import (
	"fmt"
)

func fibonacci_recursive(n int) uint64 {
	if n == 0 || n == 1 {
		return uint64(n)
	} else {
		return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)
	}
}

func fibonacci_dp1(n int) uint64 {
	dict := map[int]uint64{0: 0, 1: 1}
	for i := 2; i < n+1; i++ {
		if dict[i] == 0 { // is it better way to handle this?
			dict[i] = dict[i-1] + dict[i-2]
		}
	}
	return dict[n]
}

var resultTbl map[int]uint64 = map[int]uint64{0: 0, 1: 1}

func fibonacci_dp2(n int) uint64 {
	if n == 0 || n == 1 {
		return uint64(n)
	} else {
		if resultTbl[n] != 0 {
			return resultTbl[n]
		} else {
			resultTbl[n] = fibonacci_dp2(n-1) + fibonacci_dp2(n-2)
			return resultTbl[n]
		}
	}
}

func exec(f func uint64) uint64 {
	ch := make(chan uint64)
	// TODO make a helper function can execute the task in different thread
}

func main() {
	fmt.Printf("result %d \n", fibonacci_recursive(10))
	fmt.Printf("result %d \n", fibonacci_dp1(100))
	fmt.Printf("result %d \n", fibonacci_dp2(100))
}
