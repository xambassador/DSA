#include <iostream>
#include <string>
using std::boolalpha;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    int m1[256]{}, m2[256]{};
    for (int i{}; i < s.size(); ++i) {
        if (m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

// -----------------------------------------------------------------------------
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << boolalpha << isIsomorphic(s1, s2) << endl;
}
