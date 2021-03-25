### Strange order
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty: <br>
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.<br>
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
### Input format
Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.
### Output format
Print n integers — array a .
### Sample Input:
5
### Sample Output:
5 4 2 3 1
### Explanation
It's needed 4 iterations to create array a:
Add 5 <br>
Add 4 and 2 <br>
Add 3 <br>
Add 1