### Counting Strings
Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings 't' with length equal to that of 's', also consisting of upper case alphabets are there satisfying the following conditions:<br>
-> String 't' is lexicographical larger than string 's'.<br>
-> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.<br>
Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.<br>
### Input Format:
The first and only line of input contains the string s.
### Output Format:
Output the number of strings (t) %(10^9 + 7) in new line.
### Constraints:
1 <= |S| <= 10^5<br>
### Sample Input 1:
A
### Sample Output 1:
25
### Sample Input 2:
XKS
### Sample Output 2:
523