### Number Of Factors
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
### Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
### Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
### Constraints
T < 10000 <br>
1 ≤ a ≤ b ≤ 10^6 <br>
0 ≤ n ≤ 10
### Sample Input
5 <br>
1 3 1 <br>
1 10 2 <br>
1 10 3 <br>
1 100 3 <br>
1 1000 0 <br>
### Sample Output
2 <br>
2 <br>
0 <br>
8 <br>
1