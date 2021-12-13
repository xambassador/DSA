#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::string;

int editDistance(string s, string t) {
    // Base case
    if(s.size() == 0 || t.size() == 0) return max(s.size(), t.size());

    int ans{};
    if(s[0] == t[0]) ans = editDistance(s.substr(1), t.substr(1));
    else {
        int insertionCost{1 + editDistance(s.substr(1), t)};
        int deletionCost{1 + editDistance(s, t.substr(1))};
        int replaceCost{1 + editDistance(s.substr(1), t.substr(1))};
        ans = min(insertionCost, min(deletionCost, replaceCost));
    }
    return ans;
}

int editDistanceHelp(string s, string t, int** dp) {
    // Base case
    int m{(int) s.size()};
    int n{(int) t.size()};
    if(s.size() == 0 || t.size() == 0) return max(s.size(), t.size());

    // check for answer is already calculated
    if(dp[m][n] != -1) return dp[m][n];

    int ans{};
    if(s[0] == t[0]) ans = editDistanceHelp(s.substr(1),t.substr(1), dp);
    else {
        int insertionCost{1 + editDistanceHelp(s.substr(1), t, dp)};
        int deletionCost{1 + editDistanceHelp(s, t.substr(1), dp)};
        int replaceCost{1 + editDistanceHelp(s.substr(1), t.substr(1), dp)};
        ans = min(insertionCost, min(deletionCost, replaceCost));
    }
    dp[m][n] = ans;
    return ans;
}

int editDistanceM(string s, string t) {
    int m{(int) s.size()};
    int n{(int) t.size()};
    int** dp{new int*[m + 1]};
    for(int i{}; i <= m; i++) {
        dp[i] = new int[n + 1];
        for(int j{}; j <= n; j++) dp[i][j] = -1;
    }
    int ans{editDistanceHelp(s, t, dp)};
    for(int i{}; i <= m; i++) delete [] dp[i];
    delete [] dp;
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    int ans {editDistance(s,t)};
    int ans1 {editDistanceM(s,t)};
    cout << ans << " " << ans1 << endl;
}
