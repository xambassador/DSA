## Horrible Queries
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are - <br>
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.<br>
1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
### Input
In the first line you'll be given T, number of test cases.<br>
Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.<br>
### Output
Print the answers of the queries.
### Input:
1 <br>
8 6 <br>
0 2 4 26 <br>
0 4 8 80 <br>
0 4 5 20 <br>
1 8 8 <br>
0 5 7 14 <br>
1 4 8
### Output:
80  <br>
508