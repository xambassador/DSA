#include<iostream>
#include<string.h>
using std::string;
using std::boolalpha;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

// find longest prefix which is equal to longest suffix
int* lps(string pattern) {
    int* lpsArr{new int[pattern.length()]};
    lpsArr[0] = 0;
    int i{1}, j{};
    while (i < pattern.length()) {
        if (pattern[i] == pattern[j]) {
            lpsArr[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lpsArr[j - 1];
            } else {
                lpsArr[i] = 0;
                i++;
            }
        }
    }
    return lpsArr;
}

// -----------------------------------------------------------------------------
bool kmp(string s, string pattern) {
    int lengthOfs{s.length()};
    int lenghtOfpattern{pattern.length()};

    int i{}, j{};
    int* _lps{lps(pattern)};
    while (i < lengthOfs && j < lenghtOfpattern) {
        if (s[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = _lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (j == lenghtOfpattern) return true;
    return false;
}

// -----------------------------------------------------------------------------
int main() {
    string s, p;
    cin >> s >> p;
    cout << boolalpha << kmp(s, p) << endl;
}
