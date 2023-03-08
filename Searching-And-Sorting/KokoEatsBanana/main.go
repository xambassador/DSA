package main

import "math"

func maxElement(piles []int) int {
	max := piles[0]
	for i := 1; i < len(piles); i++ {
		if piles[i] > max {
			max = piles[i]
		}
	}
	return max
}

func minEatingSpeed(piles []int, h int) int {
	maxElement := maxElement(piles)
	minElement := 1
	k := 0
	start := minElement
	end := maxElement

	for start <= end {
		mid := start + (end-start)/2
		var totalHours int64 = 0
		for i := 0; i < len(piles); i++ {
			var hours int64 = int64(math.Ceil(float64(piles[i]) / float64(mid)))
			totalHours += hours
		}

		if totalHours <= int64(h) {
			k = mid
			end = mid - 1
		} else {
			start = mid + 1
		}
	}

	return k
}
