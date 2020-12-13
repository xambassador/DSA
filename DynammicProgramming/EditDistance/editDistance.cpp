#include<iostream>
#include<string>


int editDistance(std::string s, std::string t) {
    // Base case
    if(s.size() == 0 || t.size() == 0) {
        return std::max(s.size(), t.size());
    }

    int ans{};
    if(s[0] == t[0]) {
        ans = editDistance(s.substr(1),t.substr(1));
    }else {
        int insertionCost {1 + editDistance(s.substr(1),t)};
        int deletionCost {1 + editDistance(s,t.substr(1))};
        int replaceCost {1 + editDistance(s.substr(1), t.substr(1))};
        ans = std::min(insertionCost, std::min(deletionCost, replaceCost));
    }
    return ans;
}

int editDistanceHelp(std::string s, std::string t, int** dp) {
    // Base case
    int m {(int)s.size()};
    int n {(int)t.size()};
    if(s.size() == 0 || t.size() == 0) {
        return std::max(s.size(), t.size());
    }

    // check for answer is already calculated
    if(dp[m][n] != -1) {
        return dp[m][n];
    }

    int ans{};
    if(s[0] == t[0]) {
        ans = editDistanceHelp(s.substr(1),t.substr(1), dp);
    }else {
        int insertionCost {1 + editDistanceHelp(s.substr(1),t, dp)};
        int deletionCost {1 + editDistanceHelp(s,t.substr(1), dp)};
        int replaceCost {1 + editDistanceHelp(s.substr(1), t.substr(1), dp)};
        ans = std::min(insertionCost, std::min(deletionCost, replaceCost));
    }
    dp[m][n] = ans;
    return ans;
}

int editDistanceM(std::string s, std::string t) {
    int m {(int)s.size()};
    int n {(int)t.size()};
    int** dp {new int*[m+1]};
    for(int i{}; i<=m; i++) {
        dp[i] = new int[n+1];
        for(int j{}; j<=n; j++) {
            dp[i][j] = -1;
        }
    }
    int ans {editDistanceHelp(s,t,dp)};
    for(int i{}; i<=m; i++) {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    int ans {editDistance(s,t)};
    int ans1 {editDistanceM(s,t)};
    std::cout << ans << " " << ans1 << std::endl;
}