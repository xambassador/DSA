package main

import "fmt"

/*

n = 4

A B C D
B C D E
C D E F
D E F G


*/

func main() {
	var n int
	fmt.Scan(&n)

	row := 1
	initialValue := 'A'

	for row <= n {
		col := 1
		value := initialValue
		for col <= n {
			fmt.Print(string(value), " ")
			value++
			col++
		}
		fmt.Print("\n")
		initialValue++
		row++
	}
}