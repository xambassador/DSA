package main

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func minimizeArrayValue(nums []int) int {
	sum := 0
	res := 0

	for i, num := range nums {
		sum += num
		res = max(res, (sum+i)/(i+1))
	}

	return res
}
