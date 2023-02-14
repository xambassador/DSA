package main

import "fmt"

func addBinary(a, b string) string {
	result := ""
	carry := 0
	i := len(a) - 1
	j := len(b) - 1

	for i >= 0 || j >= 0 {
		sum := carry
		if i >= 0 {
			sum += int(rune(a[i]) - rune('0'))
			i--
		}

		if j >= 0 {
			sum += int(rune(b[j]) - rune('0'))
			j--
		}

		result = string(rune(sum%2+'0')) + result
		carry = sum / 2
	}

	if carry == 1 {
		result = "1" + result
	}

	return result
}

func main() {
	a := "11"
	b := "1"
	fmt.Println(addBinary(a, b))
}
