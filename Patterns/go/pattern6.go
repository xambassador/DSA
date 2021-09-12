// n = 4

// 4 3 2 1
// 4 3 2 1
// 4 3 2 1
// 4 3 2 1


package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	
	row := 1
	for row <= n {
		col := 1
		val := n
		for col <= n {
			fmt.Printf("%d", val)
			col++
			val--
		}
		row++
		fmt.Printf("\n")
	}
}