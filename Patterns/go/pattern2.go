// n = 4

// 1
// 2 3
// 4 5 6
// 7 8 9 10

package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	row := 1
	val := 1
	for row <= n {
		col := 1
		for col <= row {
			fmt.Printf("%d", val)
			col++
			val++
		}
		row++
		fmt.Printf("\n")
	}
}