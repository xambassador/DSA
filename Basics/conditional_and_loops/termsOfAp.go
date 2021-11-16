/*
Terms of AP

Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
N varies from 1 to 1000.

Input format :
Integer x

Output format :
Terms of series (separated by space)

Sample Input 1 :
10

Sample Output 1 :
5 11 14 17 23 26 29 35 38 41

Sample Input 2 :
4

Sample Output 2 :
5 11 14 17

*/
package main

import "fmt"

func main() {
	var x int	
	fmt.Scanln(&x)

	var count int = 0
	var n int = 1

	for count < x {
		ap := (3*n) + 2
		if ap % 4 != 0 {
			count++
			fmt.Print(ap, " ")
		}
		n++
	}

}