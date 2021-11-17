/*

Binary to decimal

Given a binary number as an integer N, convert it into decimal and print.
Input format :
An integer N
Output format :
Corresponding Decimal number (as integer)
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7

*/

package main

import "fmt"

func main() {
	var n int
	fmt.Scanln(&n)

	var binary int
	var i int = 1

	for n != 0 {
		x := n % 10
		binary = (x * i) + binary;
		i *= 2
		n /= 10
	}

	fmt.Println(binary)
}