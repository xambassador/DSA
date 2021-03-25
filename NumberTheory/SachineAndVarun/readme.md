### Sachin And Varun Problem
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:<br>
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or number of times b is used is different in the two ways.<br>
### Input Format:
The first line of input consists of an integer <br>
T denoting the number of test cases.<br>
Each test case consists of only one line containing three space separated integers a, b and d.
### Output Format:
For each test case, print the answer in a separate line.
### Constraints:
1 ≤T≤ 10^5 <br>
1 ≤ a < b ≤ 10^9 <br>
0≤d≤10^9
### Sample Input 1
4 <br>
2 3 7 <br>
4 10 6 <br>
6 14 0 <br>
2 3 6
### Sample Output 1
1 <br>
0 <br>
1 <br>
2
### Explanation
Test case 1: 7 can only be achieved by using 2 two times and 3 one time.<br>
Test case 2: 6 can't be achieved by using 4 and 10 .So, 0ways are there.