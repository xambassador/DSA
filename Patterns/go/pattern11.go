package main

import "fmt"

/*
n = 4

*
* *
* * *
* * * *

*/

func main() {
	var n int
	fmt.Scan(&n)

	row := 1
	for row <= n {
		col := 1

		for col <= row {
			fmt.Print("*")
			col++
		}
		
		fmt.Print("\n")
		row++
	}
}