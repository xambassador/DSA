package main

import "fmt"

/*
Sum of even & odd

Write a program to input an integer N and print the sum of all its even digits and sum of all its odd digits separately.
Digits means numbers not the places. That is, if the given integer is "13245", even digits are 2 & 4 and odd digits are 1, 3 & 5.

Input format :
Integer N

Output format :
Sum_of_Even_Digits Sum_of_Odd_Digits
(Print first even sum and then odd sum separated by space)

Sample Input :
1234

Sample Output :
6 4

*/

func main() {
	var n int
	fmt.Scanf("%d", &n)

	var (
		sumEven int
		sumOdd  int
	)

	for n != 0 {
		currentDigit := n % 10
		if currentDigit%2 == 0 {
			sumEven += currentDigit
		} else {
			sumOdd += currentDigit
		}

		n /= 10
	}

	fmt.Println(sumEven, sumOdd)
}
