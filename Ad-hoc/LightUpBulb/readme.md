## Light Up the Bulbs
A bulb can be ‘ON’ or ‘OFF’. Mr. Navdeep got ‘n’ number of bulbs and their status, whether they are ‘ON’ or ‘OFF’. Their status is represented in a string of size ‘n’ consisting of 0’s and 1’s, where ‘0’ represents the bulb is in ‘OFF’ condition and ‘1’ represent the bulb is ‘ON’. Mr. Navdeep has been given the task to light up all the bulbs.<br>
He can perform two operations. <br>
First, chose any segment of bulbs and reverse them means chose any substring and reverse it. E.g. “0 110 001” -> “0 011 001”. Substring (1, 3) is reversed here. This operation will cost him Rs. ‘X’.<br>
Second, chose any segment of bulbs and reverse their present condition. i.e. if the bulb is ‘ON’, make it ‘OFF’ and if it is ‘OFF’, make it ‘ON’. E.g. “0 011 001” -> “0 100 001”. Substring (1, 3) is complemented. This operation will cost him Rs. ‘Y’.<br>
You need to help Mr. Navdeep that how much minimum amount it will require to make all the bulbs lightened. (or make all the characters as ‘1’ in the representation string)
### Input Format:
The first line will contain three space separated integers: ‘n’, ‘X’, ‘Y’ denoting the number of bulbs, cost of first operation and cost of second operation respectively.<br>
The second line contains a representation string of length ‘n’ consisting of 0’s and 1’s representing whether the bulb is ‘OFF’ or ‘ON’.<br>
### Output Format:
Print a single integer denoting the minimum cost required to light up all the bulbs.
### Constraints:
1 <= n <= 3,00,000 <br>
0 <= X, Y <= 10^9 <br>
Time Limit: 1 second
### Sample Input:
5 1 10 <br>
01000
### Sample Output:
11
### Explanation:
First, Reverse substring (0, 1): “01000” -> “10000”, COST = 1 <br>
Second, Invert substring (1, 4): “10000” -> “11111”, COST = 10 <br>
Total cost = 1+10 => 11
