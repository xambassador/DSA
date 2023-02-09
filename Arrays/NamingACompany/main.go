package main

import "fmt"

func distinctNames(ideas []string) int64 {
	groups := make([]map[string]bool, 26)

	for _, idea := range ideas {
		fmt.Println(idea)
		if len(groups[idea[0]-'a']) > 0 {
			groups[idea[0]-'a'][idea[1:]] = true
		} else {
			groups[idea[0]-'a'] = map[string]bool{idea[1:]: true}
		}
	}

	ans := int64(0)
	for i := 0; i < 25; i++ {
		for j := i + 1; j < 26; j++ {
			commonSuffix := 0

			for ideaA := range groups[i] {
				if groups[j][ideaA] {
					commonSuffix++
				}
			}

			ans += int64(2 * (len(groups[i]) - commonSuffix) * (len(groups[j]) - commonSuffix))
		}
	}

	return ans
}

func main() {
	ideas := []string{"coffee", "donuts", "time", "toffee"}
	fmt.Println(distinctNames(ideas))
}
