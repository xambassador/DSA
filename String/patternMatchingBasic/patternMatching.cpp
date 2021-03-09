#include<iostream>
#include<string.h>
using namespace std;


// Basic pattern searching


// O (n * m)
bool searchPattern(string s, string p) {
    int n {s.length()};
    int m {p.length()};

    for (int i{}; i<=(n-m); i++ ) {
        bool isFound {true};
        for (int j{};j<m; j++) {
            if (s[i+j] != p[j]) {
                isFound = false;
                break;
            }
        }

        if (isFound) return true;
    }

    return false;
}


bool searchPatternRec(string s, string p) {

    if (s.length() < p.length()) return false;
    
    bool ans {searchPatternRec(s.substr(1), p)};

    if (ans) return ans;

    if (s[0] != p[0]) return false;

    bool isFound {true};
    for (int i{1}, j{1}; i<s.length() && j<p.length(); i++) {
        if (s[i] != p[j]) {
            isFound = false;
            break;
        } 

        if (i < s.length() && j<p.length() && j == p.length() - 1) {
            if (s[i] == p[j]) {
                isFound = true;
                break;
            }
        } 
    }

    return isFound;
}

int main() {
    string s;
    string p;
    cin >> s >> p;
    cout << boolalpha << searchPattern(s,p) << endl;
    cout << boolalpha << searchPatternRec(s,p) << endl;
}