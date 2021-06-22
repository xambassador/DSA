package main

import "fmt"

func main () {
	const size int = 1e9
	
	var arr [size]int

	var n int
	fmt.Scanf("%d", &n)

	var front, back, value int = 0, n-1, 1

	for front < back {
		arr[front] = value
		value++
		arr[back] = value
		value++
		front++
		back--
		if (front == back) {
			arr[front] = value
			break
		} 
	}

	for i:=0; i<n; i++ {
		fmt.Printf("%d ", arr[i])
	}
}