package main

import "fmt"

func quiz3Nplus1(n int, mSum int) int {
	if n <= 1 {
		return mSum
	} else if n%2 == 1 {
		return quiz3Nplus1(n*3+1, mSum+1)
	} else {
		return quiz3Nplus1(n/2, mSum+1)
	}
}

func main() {
	max := 0
	nums := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	for q := range nums {
		tmp := quiz3Nplus1(q, 1)
		if tmp > max {
			max = tmp
		}
	}
	fmt.Printf("max len : %d\n", max)
}
