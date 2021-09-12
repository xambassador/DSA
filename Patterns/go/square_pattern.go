package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	i := 1
	for i<=N {
		j := 1
		for j<=N {
			fmt.Printf("%d", N)
			j++
		}
		fmt.Printf("\n")
		i++
	}
}