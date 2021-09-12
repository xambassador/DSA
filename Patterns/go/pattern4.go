// n = 4

// 1111
// 2222
// 3333
// 4444

package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	
	row := 1
	for row <= n {
		col := 1
		for col <= n {
			fmt.Printf("%d", row)
			col++
		}
		row++
		fmt.Printf("\n")
	}
}