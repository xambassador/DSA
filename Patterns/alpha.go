package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	row := 1
	p := "A"
	for row <= N {
		col := 1
		for col <= row {
			fmt.Printf("%s",p)
			col++
		}
		p = string(p[0] + 1)
		row++
		fmt.Printf("\n")
	}
}
