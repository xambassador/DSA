package main

import "fmt"

func arrangeArray(arr []int, n int) {
	var start, end, number int = 0, n - 1, 1

	for start <= end {
		if (start == end) {
			arr[start] = number
			start++
			end--
			continue
		}

		arr[start] = number
		number++
		arr[end] = number
		number++
		start++
		end--
	}
}

func main() {
	var testCase, n int
	var arr = make([]int, 10000)
	fmt.Scanf("%d", &testCase)

	for testCase > 0 {
		fmt.Scanf("%d", &n)
		arrangeArray(arr, n)

		for i := 0; i < n; i++ {
			fmt.Printf("%d ", arr[i])
		}

		testCase--
	}
}
