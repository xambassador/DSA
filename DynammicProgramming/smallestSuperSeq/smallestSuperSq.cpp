#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;
using std::min;

// Brute force
int shortestSuperSq(string s, string t) {
    if (s.empty() && t.empty()) return 0;
    if (s.empty() || t.empty()) return max(s.length(), t.length());

    int ans{};
    if (s[0] == t[0]) ans = shortestSuperSq(s.substr(1), t.substr(1)) + 1;
    else {
        int ans1{shortestSuperSq(s, t.substr(1))};
        int ans2{shortestSuperSq(s.substr(1), t)};
        ans = min(ans1,ans2) + 1;
    }
    return ans;
}

// Memoization
int shortestSuperSq(string s, string t, int** dp) {
    int n {(int) s.length()}, m{(int) t.length()};
    if (n == 0 && m == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (n == 0 || m == 0) return max(n,m);
    int ans{};
    if (s[0] == t[0]) ans = shortestSuperSq(s.substr(1), t.substr(1), dp) + 1;
    else {
        int ans1{shortestSuperSq(s, t.substr(1))};
        int ans2{shortestSuperSq(s.substr(1), t)};
        ans = min(ans1,ans2) + 1;
    }
    dp[n][m] = ans;
    return ans;
}

//dp
int shortestSuperSqDp(string s, string t) {
    int n{(int) s.length()};
    int m{(int) t.length()};
    int dp[n + 1][m + 1];
    dp[n][m] = 0;
    for(int i{n - 1}, j{1}; i >= 0; i--) {
        dp[i][m] = j;
        j++;
    }

    for(int i{m - 1}, j{1}; i >= 0; i--) {
        dp[n][i] = j;
        j++;
    }

    for(int i{n - 1}; i >= 0; i--) {
        for(int j{m - 1}; j >= 0; j--) {
            if(s[i] == t[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
            else dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
        }
    }
    return dp[0][0];
}

int main() {
    string s, t;
    cin >> s >> t;
    int ans{shortestSuperSq(s, t)};
    cout << ans << endl;

    int** dp{new int*[s.length() + 1]};
    for(int i{}; i < s.length() + 1; i++) {
        dp[i] = new int[t.length() + 1];
        for(int j{}; j < t.length() + 1; j++) dp[i][j] = -1;
    }
    ans = shortestSuperSq(s, t, dp);
    cout << ans << endl;
    ans = shortestSuperSqDp(s, t);
    cout << ans << endl;
}
