package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	row := 1
	for row <= n {
		col := 1
		value := row
		for col <= row {
			fmt.Print(value, " ")
			col++
			value--
		}
		fmt.Print("\n")
		row++
	}

}