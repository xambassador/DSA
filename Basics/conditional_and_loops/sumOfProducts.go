/*

computing the sum and computing the product of 1 ,..., N.
If user enters C is equal to -
 1 : Print sum of 1 to N numbers
 2 : Print product of 1 to N numbers
 Any other number : print -1
Input format :
Line 1 : Integer N
Line 2 : Choice C (1 or 2)
Output Format :
 Sum or product according to user's choice
Sample Input 1 :
10
1
Sample Output 1 :
55
Sample Input 2 :
10
2
Sample Output 2 :
3628800
Sample Input 3 :
10
4
Sample Output 3 :
-1


*/

package main

import "fmt"

func main(){
	var n, c int
	fmt.Scanln(&n)
	fmt.Scanln(&c)

	var (
		sum int = 0
		product int = 1
	)

	if c == 1 {
		for i := 1; i <= n; i++ {
			sum += i
		}
		fmt.Println(sum)
	} else {
		for i := 1; i <= n; i++ {
			product *= i
		}
		fmt.Println(product)
	}
}