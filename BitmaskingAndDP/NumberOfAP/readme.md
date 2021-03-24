### Number of APs
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.<br>
Note: Empty sequence or single element sequence is Arithmetic Progression.
### Input Format:
First Line: N (the size of the array)<br>
Second Line: Elements of the array separated by spaces.
### Output:
Print total number of subsequences
### Input Constraints:
1 <= arr[i] <= 1000<br>
1 <= sizeof(arr) <= 1000
### Sample Input 1 :
3<br>
1 2 3
### Sample output:
8
### Sample Output Explanation:
Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }
### Sample Input 2:
7<br>
1 2 3 4 5 9 10
### Sample Output:
37