### FILLMTR
Fill The Matrix <br/>
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.<br/>
You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.<br/>
### Input
The first line of the input contains an integer T denoting the number of test cases.<br/>
The first line of each test case contains two space separated integers N, Q.<br/>
Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.<br/>
### Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
### Constraints
1 ≤ T ≤ 10^6 <br/>
2 ≤ N ≤ 10^5 <br/>
1 ≤ Q ≤ 10^6 <br/>
1 ≤ i, j ≤ N <br/>
0 ≤ val ≤ 1 <br/>
Sum of each of N, Q over all test cases doesn't exceed 106 <br/>
### Input
4 <br/>
2 2 <br/>
1 1 0 <br/>
1 2 1 <br/>
2 3 <br/>
1 1 0 <br/>
1 2 1 <br/>
2 1 0 <br/>
3 2 <br/>
2 2 0 <br/>
2 3 1 <br/>
3 3 <br/>
1 2 1 <br/>
2 3 1 <br/>
1 3 1 <br/>
### Output
yes <br/>
no <br/>
yes <br/>
no 