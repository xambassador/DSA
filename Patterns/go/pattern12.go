package main

/*

n = 4

1
2 2
3 3 3
4 4 4 4


*/

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	row := 1
	for row <= n {
		col := 1
		for col <= row {
			fmt.Print(row, " ")
			col++
		}
		fmt.Print("\n")
		row++
	}
}