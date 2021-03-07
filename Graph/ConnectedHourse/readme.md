### Connected horses
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar <br/>
N*M size board with similar arrangement of black and white 
cells.<br/>
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
### Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.<br/>

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
### Output:
For each test case, output the number of photographs taken by photographer.
### Constraints:
1<=T<=10 <br/>
1<=N,M<=1000 <br/>
1<=Q<=N*M <br/>
### SAMPLE INPUT
2 <br/>
4 4 4 <br/>
1 1 <br/>
1 2 <br/>
3 1 <br/>
3 2 <br/>
4 4 4 <br/>
1 1 <br/>
1 2 <br/>
3 1 <br/>
4 4 
### SAMPLE OUTPUT
4 <br/>
2 