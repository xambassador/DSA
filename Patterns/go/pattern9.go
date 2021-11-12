package main

import "fmt"

/*

n = 4

A B C D
A B C D
A B C D
A B C D

*/


func main() {
	var n int
	fmt.Scan(&n)
	
	row := 1
	for row <= n {
		col := 1
		value := 'A'
		for col <= n {
			fmt.Print(string(value), " ")
			value++
			col++
		}
		fmt.Print("\n")
		row++
	}
}