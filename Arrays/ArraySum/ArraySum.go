package main

import "fmt"

func sum(arr []int) int {
	var ans, n int = 0, len(arr)
	for i := 0; i < n; i++ {
		ans += arr[i]
	}
	return ans
}

func main () {
	var n int
	var arr = make([]int, 1000000)
	fmt.Scanf("%d", &n)

	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
	}

	var ans int = sum(arr[:n])
	fmt.Printf("%d", ans)
}
