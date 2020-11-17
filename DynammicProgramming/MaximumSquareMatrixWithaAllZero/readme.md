## Maximum Square Matrix With All Zeros
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
### Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.<br>
Second-line onwards, the next 'N' lines or rows represent the ith row values. <br>
Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
### Output Format:
Print the size of maximum square sub-matrix.
### Constraints :
0 <= N <= 10^4 <Br>
0 <= M <= 10^4 <Br>
Time Limit: 1 sec 
### Sample Input 1:
3 3 <br>
1 1 0 <Br>
1 1 1 <br>
1 1 1 
### Sample Output 1:
1
### Sample Input 2:
4 4 <br>
0 0 0 0 <br>
0 0 0 0 <br>
0 0 0 0 <br>
0 0 0 0
### Sample Output 2:
4
