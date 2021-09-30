package main

import "fmt"

func main () {
	const size int = 1e6
	
	var (
		arr [size]int
		sum int
		n int
	)

	fmt.Scanf("%d", &n)

	for i:=0; i<n; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	for i:=0; i<n; i++ {
		sum += arr[i]
	}

	fmt.Printf("%d\n", sum)
}