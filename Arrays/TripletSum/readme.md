# Triplet Sum
You have been given a random integer array/list(ARR) and a number X. Find and return the number of triplets in the array/list which sum to X.<br>
##### Note :
Given array/list can contain duplicate elements.

# Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.<br>
First line of each test case or query contains an integer 'N' representing the size of the first array/list.<br>
Second line contains 'N' single space separated integers representing the elements in the array/list.<br>
Third line contains an integer 'X'.<br>

# Output format :
For each test case, print the total number of triplets present in the array/list.<br>
Output for every test case will be printed in a separate line.<br>

# Constraints :
1 <= t <= 50 <br>
0 <= N <= 10^2<br>
0 <= X <= 10^9<br>
Time Limit: 1 sec<br>

# Sample Input 1:
1 <br>
7 <br>
1 2 3 4 5 6 7 <br>
12
# Sample Output 1:
5
# Sample Input 2:
2 <br>
7 <br>
1 2 3 4 5 6 7  <br>
19 <br>
9 <br>
2 -5 8 -6 0 5 10 11 -3 <br>
10
# Sample Output 2:
0 <br>
5 

# Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.<br>
For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)