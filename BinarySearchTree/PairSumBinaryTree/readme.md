## Pair sum BInary Tree
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.<br/>
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
### Input format :
Line 1 : Elements in level order form (separated by space)<br/>
(If any node does not have left or right child, take -1 in its place)<br/>
Line 2 : Integer S
### Output Format :
Each pair in different line (pair elements separated by space)
### Constraints :
1 <= N <= 1000
### Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1<br/>
15
### Sample Output 1:
5 10<br/>
6 9