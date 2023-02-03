#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

string convert(string s, int numRows) {
    // If numRows is 1, then the string is returned as it is.
    if (numRows == 1) return s;
    // res contains the converted string.
    string res {""};
    int n {(int)s.size()};
    // cycleLen: The length of the cycle. 1 cycle means go down numRows - 1 times and then go up numRows - 1 times with
    // jumping one column. So, cycleLenght specifies the number of jumps need to complete one cycle. Or simply, it is
    // the number that needs to skip to reach the next column where the next character is present.
    int cycleLen {(2 * numRows) - 2};
    for (int i{}; i < numRows; ++i) {
        for (int j{}; j + i < n; j += cycleLen) {
            res += s[j + i];
            // If i is not the first row or the last row, then the character at j + cycleLen - i is also a part of the
            // same cycle.
            if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                res += s[j + cycleLen - i];
            }
        }
    }
    return res;
}
