package main

import (
	"fmt"
)

// STILL HAS ISSUE

func mergeSort(arr [9]int) []int {
	if len(arr) == 1 {
		return arr
	}
	return merge(mergeSort(arr[0:len(arr)/2]), mergeSort(arr[len(arr)/2:]))
}

func merge(al []int, ar []int) []int {
	arrLen := len(al) + len(ar)
	r := new([arrLen]int)
	lidx := 0
	ridx := 0
	for lidx < len(al) && ridx < len(ar) {
		if al[lidx] < ar[ridx] {
			r.append(al[lidx])
			lidx++
		} else {
			r.append(ar[ridx])
			ridx++
		}
	}
	if lidx < len(al) {
		r = r + al[lidx:]
	}
	if ridx < len(ar) {
		r = r + ar[ridx:]
	}
	return r
}

func main() {
	arr := [9]int{23, 8, 4, 662, 0, 456, 45, 645, 64}
	for i := range mergeSort(arr) {
		fmt.Printf("%d ", i)
	}
}
