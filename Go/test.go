package main

import (
	"fmt"
)

func main() {
	sum := 0
	array := [...]int{1, 2, 3}
	for _, value := range array {
		sum += value
		fmt.Println("value ", value)

	}
}
