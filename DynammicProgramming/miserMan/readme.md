## Miser Man
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:<br>
1. At every city, he has to change the bus.<br>
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.<br>
You are to help Jack to go from A to B by spending the minimum amount of money. <br>
N, M, K <= 100. <br>
### Input
Line 1:    N M <br>
Line 2:    NxM Grid <br>
Each row lists the fares the M busses to go form the current city to the next city.<br>
### Output
Single Line containing the minimum amount of fare that Jack has to give.
### Sample Input
5 5 <br>
1  3  1  2  6 <br>
10 2  5  4  15 <br>
10 9  6  7  1 <br>
2  7  1  5  3 <br>
8  2  6  1  9 <br>
### Sample Output
10
