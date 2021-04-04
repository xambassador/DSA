### Innocent Swaps and His Emotions
There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.<br>
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.<br>
Swaps, being a very sensitive guy, doesn't like to mix his emotions in a particular day. So each day, he is in exactly one of the three phases.<br>
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
### Input:
The first line of the input contains T, denoting the number of test cases.<br>
The next T lines contain two space-separated integers N and K. <br>
### Output:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
### Constraints:
1 ≤ T ≤ 10^5 <br>
1 ≤ N ≤ 10^6 <br>
1 ≤ K ≤ 10^6 <br>
K ≤ N <br>
### Sample Input :
3 <br>
1 1 <br>
2 1 <br>
3 2 <br>
### Sample Output:
2 <br>
4 <br>
12 <br>
### Explanation
In the first test case, he needs to be happy on Day 1. Hence, answer is 2 (He can either play or sleep).<br>
In the second test case, he can be happy either on Day 1 or Day 2. So number of ways = 4.