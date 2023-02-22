package main

func canFinish(weights []int, days, capacity int) bool {
	var i int
	for days > 0 {
		var sum int
		for sum+weights[i] <= capacity {
			sum += weights[i]
			i++
			if i == len(weights) {
				return true
			}
		}
		days--
	}
	return false
}

func shipWithinDays(weights []int, days int) int {
	// Sum of all weights
	var sum int
	// Sum all weights
	for _, v := range weights {
		sum += v
	}
	// Binary search
	var left, right int
	left = sum / days
	right = sum
	for left < right {
		mid := left + (right-left)/2
		if canFinish(weights, days, mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return left
}
