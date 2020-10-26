## LCA of Binary Tree
Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.<br/>
If out of 2 nodes only one node is present, return that node.<br/>
If both are not present, return -1.
### Input format :
Line 1 :  Elements in level order form (separated by space)<br/>
(If any node does not have left or right child, take -1 in its place)
Line 2 : Two integers, Node 1 and Node 2 (separated by space)<br/>
### Output Format :
LCA
### Constraints :
1 <= N <= 1000
### Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1 <br/>
2 10
###  Sample Output 1:
10
### Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1 <br/>
2 6
### Sample Output 2:
5
### Sample Input 3:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1<br/>
12 78
### Sample Output 3:
-1