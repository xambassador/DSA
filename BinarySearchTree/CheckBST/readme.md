## Check if a Binary Tree is BST
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.<br/>
Duplicate elements should be in right subtree.
### Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
### Output format :
true or false
### Constraints :
1 <= N <= 10^5
### Sample Input 1 :
3 1 5 -1 2 -1 -1 -1 -1
### Sample Output 1 :
true
### Sample Input 2 :
5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1
### Sample Output 2 :
false