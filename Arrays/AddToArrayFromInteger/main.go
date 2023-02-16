package main

import "fmt"

func reverse(nums []int) {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
}

func addToArrayForm(num []int, k int) []int {
	var result []int
	var carry int
	var i int = len(num) - 1
	for i >= 0 || k > 0 {
		var sum int = carry
		if i >= 0 {
			sum += num[i]
			i--
		}
		if k > 0 {
			sum += k % 10
			k /= 10
		}
		result = append(result, sum%10)
		carry = sum / 10
	}
	if carry > 0 {
		result = append(result, carry)
	}
	reverse(result)
	return result
}

func main() {
	arr := []int{1, 2, 0, 0}
	k := 34
	fmt.Println(addToArrayForm(arr, k))
}
