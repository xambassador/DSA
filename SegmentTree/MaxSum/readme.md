## Maximum Sum In Subarray
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.<br>
Given M queries, your program must output the results of these queries.
### Input
The first line of the input file contains the integer N.<br>
In the second line, N numbers follow.<br>
The third line contains the integer M.<br>
M lines follow, where line i contains 2 numbers xi and yi.
### Output
Your program should output the results of the M queries, one 
query per line.<br>
### Sample Input:
3 <br>
-1 2 3 <br> 
1 <br>
1 2
### Sample Output:
2