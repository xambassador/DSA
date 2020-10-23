## Create & Insert Duplicate Node
Given a Binary Tree with N number of nodes, for each node create a new duplicate node, and insert that duplicate as left child of the original node.<br/>
Note : Root will remain same. So you just need to insert nodes in the given Binary Tree and no need to print or return anything.
### Input format :
Elements in level order form (separated by space)<br/>
(If any node does not have left or right child, take -1 in its place)
### Output Format :
Level order traversal of updated tree. (Every level in new line)
### Constraints :
1 <= N <= 1000
### Sample Input :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
### Sample Output :
8 <br/>
8 10 <br/>
5 10 <br/>
5 6 <br/>
2 6 7 <br/>
2 7