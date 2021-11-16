/*
Reverse of a number

Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
Input format :
Integer N
Constraints:
Time Limit: 1 second
Output format :
Corresponding reverse number
Constraints:
N is always greater than or equal to 0
Sample Input 1 :
1234
Sample Output 1 :
4321
Sample Input 2 :
1980
Sample Output 2 :
891

*/
package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	var reverseNumber int

	for n != 0 {
		lastDigit := n % 10
		reverseNumber = reverseNumber * 10 + lastDigit
		n = n / 10
	}

	fmt.Println(reverseNumber)
}