package main

import "sort"

// https://leetcode.com/problems/boats-to-save-people/
func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	i := 0
	j := len(people) - 1
	ans := 0

	for i <= j {
		if !(people[i]+people[j] <= limit) {
			j--
			ans++
			continue
		}
		i++
		j--
		ans++
	}

	return ans
}
