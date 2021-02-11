## Vasya vs Rhezo
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.<br>
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
### Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. <br>
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi. <br>
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. <br>
Each of the next Q lines contains 2 integers Li and Ri.<br>
### Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
### Constraints:
1≤ N,Q ≤10^6 <br>
1≤ Ai,Bi ≤10^9 <br>
1≤Li≤Ri <br>
### Sample Input
5 <br>
1 8 4 6 8 <br>
4 8 6 3 7 <br>
4 <br>
1 4 <br>
2 4 <br>
3 4 <br>
1 5 
### Sample Output
2 <br>
2 <br>
4 <br>
5 