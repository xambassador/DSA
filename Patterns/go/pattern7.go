// n = 4

// ****
// ****
// ****
// ****

package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	
	row := 1
	for row <= n {
		col := 1
		for col <= n {
			fmt.Printf("*")
			col++
		}
		row++
		fmt.Printf("\n")
	}
}