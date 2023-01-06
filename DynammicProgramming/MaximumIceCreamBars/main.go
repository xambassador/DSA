package main

import "sort"

func maxIceCream(costs []int, coins int) int {
	if len(costs) == 0 {
		return 0
	}
	sort.Ints(costs)
	maximumIceCream := 0
	for _, cost := range costs {
		if cost <= coins {
			maximumIceCream++
			coins -= cost
		}
	}

	return maximumIceCream
}
