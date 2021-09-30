# Linear Search

You have been given a random integer array/list(ARR) of size N, and an integer X. You need to search for the integer X in the given array/list using 'Linear Search'.
 You have been required to return the index at which X is present in the array/list. If X has multiple occurrences in the array/list, then you need to return the index at which the first occurrence of X would be encountered. In case X is not present in the array/list, then return -1.
'Linear search' is a method for finding an element within an array/list. It sequentially checks each element of the array/list until a match is found or the whole array/list has been searched.

# Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.<br>

First line of each test case or query contains an integer 'N' representing the size of the array/list.<br>

Second line contains 'N' single space separated integers representing the elements in the array/list.<br>

Third line contains the value of X(integer to be searched in the given array/list)<br>

# Output format :
For each test case, print the index at which X is present or -1, otherwise.<br>

Output for every test case will be printed in a separate line.<br>

# Constraints :
1 <= t <= 10^2<br>
0 <= N <= 10^5<br>
-2 ^ 31 <= X <= (2 ^ 31) - 1<br>
Time Limit: 1 sec<br>

# Sample Input 1:
1<br>
7<br>
2 13 4 1 3 6 28<br>
3
# Sample Output 1:
4<br>
# Sample Input 2:
2 <br>
7 <br>
2 13 4 1 3 6 28 <br>
9 <br>
5 <br>
7 8 5 9 5 <br>
5
# Sample Output 2:
-1<br>
2