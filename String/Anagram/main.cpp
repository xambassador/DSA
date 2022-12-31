#include <iostream>
#include <string>
#include <algorithm>
using std::boolalpha;
using std::sort;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

bool isAnagram(string s, string t) {
    int sLen {(int)s.length()};
    int tLen {(int)t.length()};
    if (sLen != tLen) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i{}; i < tLen; i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
}

// -----------------------------------------------------------------------------
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << boolalpha << isAnagram(s1, s2) << endl;
}
