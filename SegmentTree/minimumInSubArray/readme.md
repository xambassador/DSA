## Minimum In SubArray
Range Minimum Query <br>
Given an array A of size N, there are two types of queries on this array.<br>
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].<br>
2) u x y: In this query you need to update A[x]=y.<br>
### Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.<br>
Second line contains N space separated integers, elements of A.<br>
Next Q lines contain one of the two queries.<br>
### Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].<br>
### Contraints:
1≤N,Q,y≤10^5 <br>
1≤l,r,x≤N <br>
### Sample Input :
5 5 <br>
1 5 2 4 3 <br>
q 1 5 <br>
q 1 3 <br>
q 3 5 <br>
u 3 6 <br>
q 1 5
### Sample Output :
1 <br>
1 <br>
2 <br>
1 <br>