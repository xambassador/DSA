package main

import "fmt"

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxDistance(grid [][]int) int {
	rows := len(grid)
	cols := len(grid[0])
	result := 0

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if grid[i][j] == 1 {
				continue
			}
			grid[i][j] = 1001
			if i > 0 {
				grid[i][j] = min(grid[i][j], grid[i-1][j]+1)
			}
			if j > 0 {
				grid[i][j] = min(grid[i][j], grid[i][j-1]+1)
			}
		}
	}

	for i := rows - 1; i >= 0; i-- {
		for j := cols - 1; j >= 0; j-- {
			if grid[i][j] == 1 {
				continue
			}
			if i < rows-1 {
				grid[i][j] = min(grid[i][j], grid[i+1][j]+1)
			}
			if j < cols-1 {
				grid[i][j] = min(grid[i][j], grid[i][j+1]+1)
			}
			result = max(result, grid[i][j])
		}
	}

	if result == 1001 {
		return -1
	}
	return result - 1
}

func main() {
	grid := [][]int{
		{1, 0, 1},
		{0, 0, 0},
		{1, 0, 1},
	}
	fmt.Println(maxDistance(grid))
}
