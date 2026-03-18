package main

import (
	"fmt"
	"math"
)

func main() {
	var (
		basic int
		grade rune
	)
	fmt.Scanf("%d %c", &basic, &grade)

	var (
		hra   = float64(basic) * 0.2
		da    = float64(basic) * 0.5
		pf    = float64(basic) * 0.11
		allow int
	)

	if grade == 'A' {
		allow = 1700
	} else if grade == 'B' {
		allow = 1500
	} else {
		allow = 1300
	}

	totalSalary := int(math.Round(float64(basic) + hra + da + float64(allow) - pf))
	fmt.Printf("%d", totalSalary)
}

/*
Total Salary

Write a program to calculate the total salary of a person. The user has to enter the basic salary (an integer) and the
grade (an uppercase character), and depending upon which the total salary is calculated as -
totalSalary = basic + hra + da + allow - pf

where :
hra   = 20% of basic
da    = 50% of basic
allow = 1700 if grade = A
allow = 1500 if grade = B
allow = 1300 if grade = C or any other character
pf    = 11% of basic.

Round off the total salary and then print the integral part only.
Note: Try finding out a function on the internet to do so.

Input format :
Basic salary & Grade (separated by space)

Output Format :
Total Salary

Sample Input 1 :
10000 A

Sample Output 1 :
17600

Sample Input 2 :
4567 B

Sample Output 2 :
8762
*/
