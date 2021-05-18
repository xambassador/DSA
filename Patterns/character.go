package main

import "fmt"

func main() {
	var N int
	fmt.Scan(&N)

	row := 1
	p := "A"

	for row <= N {
		col := 1
		start := p
		for col <= row {
			fmt.Printf("%s", start)
			col++
			start = string(start[0] + 1)
		}
		p = string(p[0] + 1)
		row++
		fmt.Printf("\n")
	}
}
