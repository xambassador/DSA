#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int lps(string& s) {
    int max{};
    int n{(int)s.length()};
    for (int i{}; i < n; i++) {
        int left{i}, right{i};

        // for odd length substring
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currentLength{right - left + 1};
            if (currentLength > max) max = currentLength;
            left--;
            right++;
        }

        //for even length substring
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int currentLength{right - left + 1};
            if (currentLength > max) max = currentLength;
            left--;
            right++;
        }
    }
    return max;
}

// -----------------------------------------------------------------------------
int main() {
    string s;
    cin >> s;
    cout << lps(s) << endl;
}
