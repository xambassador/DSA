package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	row := 1
	for row <= N {
		col := row
		for col > 0 {
			fmt.Printf("%d", col)
			col--
		}
		row++
		fmt.Printf("\n")
	}
}