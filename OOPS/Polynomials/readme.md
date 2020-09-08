## Code : Polynomial Class
Implement a polynomial class, with following properties and functions.
Properties : <br/>
### 1. An integer (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
### 2. An integer holding total size of array A.
#### Functions :
1. Default constructor <br/>
2. Copy constructor<br/>
3. setCoefficient -<br/>
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value<br/>
4. Overload "+" operator (P3 = P1 + P2) :<br/>
Adds two polynomials and returns a new polynomial which has result.<br/>
5. Overload "-" operator (P3 = p1 - p2) :<br/>
Subtracts two polynomials and returns a new polynomial which has result<br/>
6. Overload * operator (P3 = P1 * P2) :<br/>
Multiplies two polynomials and returns a new polynomial which has result<br/>
7. Overload "=" operator (Copy assignment operator) -<br/>
Assigns all values of one polynomial to other.<br/>
8. print() -<br/>
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.<br/>
Print pattern for a single term : <coefficient>"x"<degree> <br/>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases<br/>
### Input Format :
Line 1 : N, total number of terms in polynomial P1 <br/>
Line 2 : N integers representing degree of P1 (separated by space) <br/>
Line 3 : N integers representing coefficients of P1 (separated by space) <br/>
Line 4 : M, total number of terms in polynomial P2 <br/>
Line 5 : M integers representing degree of P2 (separated by space) <br/>
Line 6 : M integers representing coefficients of P2 (separated by space)<br/>
Line 7 : Integer C, choice representing the function to be called (See main for more details)<br/>
### Sample Input 1 :
3 <br/>
1 3 5<br/>
1 2 -4<br/>
4<br/>
0 1 2 3<br/>
4 2 -3 1<br/>
1<br/>
### Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
### Sample Input 2 :
3 <br/>
1 3 5 <br/>
1 2 -4 <br/>
4<br/>
0 1 2 3<br/>
4 2 -3 1 <br/>
2
### Sample Output 2 :separated
-4x0 -1x1 3x2 1x3 -4x5
### Sample Input 3 :
3 <br/>
1 3 5 <br/>
1 2 -4 <br/>
4<br/>
0 1 2 3 <br/>
4 2 -3 1 <br/>
3
### Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8