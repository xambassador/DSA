package main

func partitionString(s string) int {
	var lastSeen [26]int
	count := 1
	substringStart := 0

	// Initialize lastSeen array with -1
	for i := 0; i < 26; i++ {
		lastSeen[i] = -1
	}

	for i := 0; i < len(s); i++ {
		if lastSeen[s[i]-'a'] >= substringStart {
			count++
			substringStart = i
		}

		lastSeen[s[i]-'a'] = i
	}

	return count
}

// Using bit manipulation
func solution(s string) int {
	xr := 0
	count := 1

	for i := 0; i < len(s); i++ {
		if (xr & (1 << (s[i] - 'a'))) > 0 {
			count++
			xr = 0
		}

		xr |= (1 << (s[i] - 'a'))
	}

	return count
}
