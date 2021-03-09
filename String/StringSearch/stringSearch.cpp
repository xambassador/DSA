#include<iostream>
#include<string.h>
using namespace std;

int* lps(string p) {
    int pLength {(int) p.length()};
    int* lpsArr {new int[pLength]};
    int i{1};
    int j{};
    lpsArr[0] = 0;
    while(i < pLength) {
        if (p[i] == p[j]) {
            lpsArr[i] = j+1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lpsArr[j-1];
            } else {
                lpsArr[i] = 0;
                i++;
            }
        }
    }
    return lpsArr;
} 

int kmp(string s, string p) {
    int* _lps {lps(p)};
    int sLen {s.length()};
    int pLen {p.length()};
    int i{};
    int j{};
    while(i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = _lps[j-1];
            } else {
                i++;
            }
        }
    }
    return j == pLen ? i-j : -1;
}

int findString(char S[], char T[]) {
    string s {""};
    string p{""};
    for(int i{}; S[i] != '\0'; i++) s += S[i];
    for(int i{}; T[i] != '\0'; i++) p += T[i];
    return kmp(s,p);
}

int main() {
    string s;
    cin >> s;
    string p;
    cin >> p;
    cout << kmp(s,p) << endl;
}