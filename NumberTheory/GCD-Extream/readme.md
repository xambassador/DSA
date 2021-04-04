### GCD Extreme
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0; <br>
for(i = 1 ; i < N ; i++) <br>
   for(j = i+1 ; j <= N ; j++) <br> 
       G+=gcd(i,j); <br>
Here gcd() is a function that finds the greatest common divisor of the two input numbers.
### Input
The input file contains at most 20000 lines of inputs. Each line contains an integer N (1 < N < 1000001). The meaning of N is given in the problem statement. Input is terminated by a line containing a single zero.
### Output
For each line of input produce one line of output. This line contains the value of G for the corresponding N. The value of G will fit in a 64-bit signed integer.
### Sample Input:
10 <br>
100 <br>
200000 <br>
0 <br>
### Sample Output:
67 <br>
13015 <br>
143295493160