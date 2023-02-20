package main

import "fmt"

func helper(nums []int, target int) int {
	// If array is empty then we can insert at 0th index
	if len(nums) == 0 {
		return 0
	}
	// If array has only one element then we can insert at 0th index if target is less than that element
	if len(nums) == 1 {
		if nums[0] >= target {
			return 0
		}
		// If target is greater than that element then we can insert at 1st index
		return 1
	}
	// Get mid index
	mid := len(nums) / 2
	// If target is equal to mid element then element is already present at mid index
	if nums[mid] == target {
		return mid
	}
	// If target is less than mid element then we can insert at left side of mid element
	if nums[mid] > target {
		return helper(nums[:mid], target)
	}

	// If target is greater than mid element then we can insert at right side of mid element
	return mid + helper(nums[mid:], target)
}

func searchInsert(nums []int, target int) int {
	return helper(nums, target)
}

func main() {
	nums := []int{1, 3, 5, 6}
	target := 5
	fmt.Println(searchInsert(nums, target))
}
