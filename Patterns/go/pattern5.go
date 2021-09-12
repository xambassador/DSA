// n = 4

// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	
	row := 1
	for row <= n {
		col := 1
		for col <= n {
			fmt.Printf("%d", col)
			col++
		}
		row++
		fmt.Printf("\n")
	}
}