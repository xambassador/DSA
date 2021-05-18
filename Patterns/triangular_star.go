package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	row := 1
	for row <= N {
		col := 1
		for col <= row {
			fmt.Printf("*")
			col++
		}
		fmt.Printf("\n")
		row++
	}
}
