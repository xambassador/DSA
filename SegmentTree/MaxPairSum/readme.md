### Maximum Pair Sum
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows: <br>
#### Update: <br>
This will be indicated in the input by a 'U' followed by space and then two integers i and x.<br>
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.<br>
This operation sets the value of A[i] to x. <br>
#### Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.<br>
Q x y, 1 ≤ x < y ≤ N.<br>
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
### Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
### Output
Output the maximum sum mentioned above, in a separate line, for each Query.
### Input:
5 <br>
1 2 3 4 5 <br>
6 <br>
Q 2 4 <br>
Q 2 5 <br>
U 1 6 <br>
Q 1 5 <br>
U 1 7 <br>
Q 1 5 
### Output:
7 <br>
9 <br>
11 <br>
12 <br>