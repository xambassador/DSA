## Inversion Count
For a given integer array/list of size N, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.<br/>
A pair (arr[i], arr[j]) is said to be an inversion when,<br/>
1. arr[i] > arr[j] <br/>
2. i < j <br/>

Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N).
### Input format :
The first line of input contains an integer N, denoting the size of the array.<br/>
The second line of input contains N integers separated by a single space, denoting the elements of the array.
### Output format :
The only line of output prints the total count of inversions in the array.<br/>
Note:<br/>
You are not required to print anything. Return the total number of inversion count.
### Constraints :
1 <= N <= 10^5 <br/>
1 <= arr[i] <= 10^9 <br/>
Time Limit: 1sec<br/>
### Sample Input 1 :
3 <br/>
3 2 1 <br/>
### Sample Output 1 :
3
### Explanation of Sample Input 1:
We have a total of three pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
### Sample Input 2 :
5 <br/>
2 5 1 3 4
### Sample Output 2 :
4