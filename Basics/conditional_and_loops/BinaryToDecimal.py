""" 
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

"""
n = int(input())
binary = 0
i = 1

while n != 0:
    lastBinaryDigit = n % 10
    binary = (lastBinaryDigit * i) + binary
    i = i * 2
    n = n // 10

print(binary)