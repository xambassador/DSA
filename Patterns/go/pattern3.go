package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	row := 1
	val := 1

	for row <= n {
		space := 1
		for space <= n - row {
			fmt.Printf(" ")
			space++
		}

		col := 1
		for col <= row {
			fmt.Printf("%d", val)
			val++
			col++
		}
		row++
		fmt.Printf("\n")
	}
}