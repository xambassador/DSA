## Counting Even/Odd
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:- <br>
Query 0 :- modify the element present at index i to x. <br>
Query 1:- count the number of even numbers in range l to r inclusive. <br>
Query 2:- count the number of odd numbers in range l to r inclusive. <br>
##3 Input:
First line of the input contains the number N. Next line contains N natural numbers. <br>
Next line contains an integer Q followed by Q queries.<br>
0 x y - modify the number at index x to y. <br>
1 x y - count the number of even numbers in range l to r inclusive.<br>
2 x y - count the number of odd numbers in range l to r inclusive.
### Constraints:
1<=N,Q<=10^5<br>
1<=l<=r<=N <br>
0<=Ai<=10^9 <br>
1<=x<=N <br>
0<=y<=10^9 <br>
#### Note:- <br>
indexing starts from 1.
### Sample Input
6 <br>
1 2 3 4 5 6 <br>
4 <br>
1 2 5 <br>
2 1 4 <br>
0 5 4 <br>
1 1 6 <br>
### Sample Output
2 <br>
2 <br>
4 