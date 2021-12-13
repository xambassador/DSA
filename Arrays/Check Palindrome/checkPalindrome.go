package main

import "fmt"

// Recursive solution
func isPalindromeRec(s string, start, end int) bool {
	// Base case: If string is empty or contains only one character
	if start > end || start == end {
		return true
	}

	// My Calculation
	if s[start] == s[end] {
		return isPalindromeRec(s, start + 1, end - 1)
	} else {
		return false
	}
}

// Iterative solution
func isPalindrome(s string) bool {
	var start, end int = 0, len(s) - 1
	for start <= end {
		if s[start] != s[end] {
			return false
		}
		start++
		end--
	}
	return true
}

func main() {
	var s string
	fmt.Scanf("%s", &s)
	var ans1 bool = isPalindrome(s)
	var ans2 bool = isPalindromeRec(s, 0, len(s) - 1)
	fmt.Printf("%t\n", ans1)
	fmt.Printf("%t", ans2)
}
