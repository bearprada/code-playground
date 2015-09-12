package main

import (
	"fmt"
)

type Node struct {
	value int
	next  *Node
	prev  *Node
}

func createLinkedList(start int, end int) *Node {
	header := &Node{0, nil, nil}
	p := header
	fmt.Printf("insert datas\n")
	for i := 1; i <= 10; i++ {
		n := &Node{i, nil, p}
		p.next = n
		p = n
	}
	return header
}

func main() {
	header := createLinkedList(0, 10)
	// print result
	fmt.Printf("print result\n")
	p := header
	for p.next != nil {
		fmt.Printf("node value : %d\n", p.value)
		p = p.next
	}
	fmt.Printf("=============")
}
