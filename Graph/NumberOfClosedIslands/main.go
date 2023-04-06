package main

func dfs(x, y, m, n int, grid [][]int, visit [][]bool) bool {
	if x < 0 || x >= m || y < 0 || y >= n {
		return false
	}

	if grid[x][y] == 1 || visit[x][y] {
		return true
	}

	visit[x][y] = true
	isClosed := true
	dirx := []int{0, 1, 0, -1}
	diry := []int{-1, 0, 1, 0}

	for i := 0; i < 4; i++ {
		r := x + dirx[i]
		c := y + diry[i]

		if !dfs(r, c, m, n, grid, visit) {
			isClosed = false
		}
	}

	return isClosed
}

// https://leetcode.com/problems/number-of-closed-islands/
func closedIsland(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])

	count := 0

	visit := make([][]bool, m)
	for i := range visit {
		visit[i] = make([]bool, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 && !visit[i][j] && dfs(i, j, m, n, grid, visit) {
				count++
			}
		}
	}

	return count
}
