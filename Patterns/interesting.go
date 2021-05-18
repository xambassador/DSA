package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	row := 1
	c := string(65 + (N - 1))
	for row <= N {
		col := 1
		p := c
		for col <= row {
			fmt.Printf("%s", p)
			col++
			p = string(p[0] + 1)
		}
		c = string(c[0] - 1)
		row++
		fmt.Printf("\n")
	}
}
