package main

import "fmt"

// -----------------------------------------------------------------------------------------
func jump(nums []int) int {
	// If there is only one element, then return 0
	if len(nums) == 1 {
		return 0
	}

	// If there are only two elements, then minimum jumps will be 1
	if len(nums) == 2 {
		return 1
	}

	// needToChoose: The index of the element that we need to choose to jump
	// canReach: The index of the element that we can reach from the current index
	// jumps: The number of jumps that we need to make
	needToChoose, canReach, jumps := 0, 0, 0

	for i, num := range nums {
		// If canReach is less than the current index + the value of the current index element
		// that means we can reach a further index from the current index.
		if canReach < i+num {
			canReach = i + num
			// If canReach is greater than or equal to the last index, then we reach the last index
			// so we can return the number of jumps + 1. +1 because we need to add current jump into
			// calculation.
			if canReach >= len(nums)-1 {
				return jumps + 1
			}
		}

		// If the current index is equal to the index of the element that we need to choose to jump
		// then we need to choose the next element that we can reach from the current index.
		// and we need to do a jump.
		if needToChoose == i {
			needToChoose = canReach
			jumps++
		}
	}

	return jumps
}

// -----------------------------------------------------------------------------------------
func main() {
	nums := []int{2, 3, 1, 1, 4}
	jumps := jump(nums)
	fmt.Printf("Jumps: %d", jumps)
}
