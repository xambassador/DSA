## Check AB
Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:<br/>
a. The string begins with an 'a'<br/>
b. Each 'a' is followed by nothing or an 'a' or "bb" <br/>
c. Each "bb" is followed by nothing or an 'a'<br/>
If all the rules are followed by the given string, return true otherwise return false.
### Sample Input:
abb
### Sample Output:
true