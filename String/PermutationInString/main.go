package main

import "fmt"

// -----------------------------------------------------------------------------------------
func isSame(a, b [26]int) bool {
	for i := 0; i < 26; i++ {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

// -----------------------------------------------------------------------------------------
func checkInclusion(s1 string, s2 string) bool {
	if len(s2) < len(s1) {
		return false
	}

	var frequency [26]int = [26]int{}
	var window [26]int = [26]int{}

	for i := 0; i < len(s1); i++ {
		frequency[s1[i]-'a']++
		window[s2[i]-'a']++
	}

	if isSame(frequency, window) {
		return true
	}

	for i := len(s1); i < len(s2); i++ {
		window[s2[i]-'a']++
		window[s2[i-len(s1)]-'a']--
		if isSame(frequency, window) {
			return true
		}
	}

	return false
}

// -----------------------------------------------------------------------------------------
func main() {
	s1 := "ab"
	s2 := "eidbaooo"
	fmt.Println(checkInclusion(s1, s2))
}
