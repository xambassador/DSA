package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func shortestAlternatingPaths(n int, redEdges [][]int, blueEdges [][]int) []int {
	red := make([][]int, n)
	blue := make([][]int, n)
	for _, e := range redEdges {
		red[e[0]] = append(red[e[0]], e[1])
	}
	for _, e := range blueEdges {
		blue[e[0]] = append(blue[e[0]], e[1])
	}
	redDist := make([]int, n)
	blueDist := make([]int, n)
	for i := range redDist {
		redDist[i] = -1
		blueDist[i] = -1
	}
	redDist[0] = 0
	blueDist[0] = 0
	q := make([][3]int, 0, n)
	q = append(q, [3]int{0, 0, 0})
	q = append(q, [3]int{0, 1, 0})
	for len(q) > 0 {
		cur, color, dist := q[0][0], q[0][1], q[0][2]
		q = q[1:]
		if color == 0 {
			for _, next := range red[cur] {
				if redDist[next] == -1 {
					redDist[next] = dist + 1
					q = append(q, [3]int{next, 1, dist + 1})
				}
			}
		} else {
			for _, next := range blue[cur] {
				if blueDist[next] == -1 {
					blueDist[next] = dist + 1
					q = append(q, [3]int{next, 0, dist + 1})
				}
			}
		}
	}
	ans := make([]int, n)
	for i := range ans {
		if redDist[i] == -1 || blueDist[i] == -1 {
			ans[i] = max(redDist[i], blueDist[i])
		} else {
			ans[i] = min(redDist[i], blueDist[i])
		}
	}
	return ans
}
