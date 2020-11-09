## Winning strategy
Our college team is going to the sports fest to play a football match with our coach. There are n players in our team, numbered from 1 to n.<br>
The coach will know the position of another team hence create a winning strategy. He creates the position of every player in a specific order so that we will win and then he starts swapping two players at a time to form the positions.<br>
He swaps payers in such a way that it can't be understood by another team:<br>
1. Any player can swap with the player directly at front him <br>
2. One player can swap at most with two other players <br>
If the specific order is formed then our team will win otherwise we will lose
### Input Format
The First line contains numbers of players in team: n <br>
The second line contains n space separated integers denoting the specific position of players: i-th integer denotes the position of Ai player in winning strategy
### Output Format
If our team wins print "YES"(without quotes) and in next line print the minimum numbers of swapping required to form this specific order otherwise print "NO"(without quotes) 
### Constraints
1 =< n <= 10^5 <br>
1 <= Ai <= n
### Sample Input1:
5 <bt>
2 1 5 3 4
### Sample Output1:
YES <br>
3
### Sample Input2:
5 <br>
2 5 1 3 4
### Sample Output3:
NO   <br>
Explaination <br>
In the First Sample case, <br>
    Initial state: 1 2 3 4 5 <br>
    Three moves required to form this order: <br>
    1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4 <br>
In the second case, no way to form this specific order
