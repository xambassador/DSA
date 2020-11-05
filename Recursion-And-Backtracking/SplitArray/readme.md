## Split Array
Given an integer array A of size N, check if the input array can be splitted in two parts such that -<br/>
- Sum of both parts is equal<br/>
- All elements in the input, which are divisible by 5 should be in same group.<br/>
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.<br/>
- Elements which are neither divisible by 5 nor by 3, can be put in any group.<br/>
Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.<br/>
Return true, if array can be split according to the above rules, else return false.<br/>
Note : You will get marks only if all the test cases are passed.<br/>
### Input Format :
Line 1 : Integer N (size of array)<br/>
Line 2 : Array A elements (separated by space)
### Output Format :
true or false
### Constraints :
1 <= N <= 50
### Sample Input 1 :
2<br/>
1 2
### Sample Output 1 :
false
### Sample Input 2 :
3<br/>
1 4 3
### Sample Output 2 :
true
