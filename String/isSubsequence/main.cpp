#include <iostream>
#include <string>
using std::boolalpha;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

bool isSubsequence(string s, string t) {
    int sLen {(int)s.length()};
    int tLen {(int)t.length()};

    if (sLen > tLen) return false;

    int i {0};
    int j {0};
    while (i < sLen && j < tLen) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    return i == sLen;
}

// -----------------------------------------------------------------------------
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << boolalpha << isSubsequence(s1, s2) << endl;
}
