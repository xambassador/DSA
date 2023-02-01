#include <iostream>
#include <string>
#include <algorithm>
using std::__gcd;
using std::string;
using std::cin;
using std::cout;
using std::endl;


string gcdOfStrings(string str1, string str2) {
    // if str1 + str2 != str2 + str1, then there is no common substring
    // for example, str1 = "ABABAB", str2 = "ABAB", then str1 + str2 = "ABABABABAB", str2 + str1 = "ABABABAB"
    // so there is no common substring between str1 and str2.
    if (str1 + str2 != str2 + str1) return "";
    // take the gcd of the length of str1 and str2 as the length of the common substring
    // for example, str1 = "ABABAB", str2 = "ABAB", then gcd(6, 4) = 2, so the common substring is "AB"
    // if str1 = "LEET", str2 = "CODE", then gcd(4, 4) = 4, so the common substring is "LEET"
    // if str1 = "ABCDEF", str2 = "ABC", then gcd(6, 3) = 3, so the common substring is "ABC"
    int gcd {__gcd(str1.size(), str2.size())};
    // return the common substring
    // for example, str1 = "ABABAB", str2 = "ABAB", then str1.substr(0, 2) = "AB"
    return str1.substr(0, gcd);
}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
}
