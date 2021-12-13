#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

int blessing(string s1, string s2, int k, int dp[][101][101]) {
    if(k == 0) return 0;

    if(k > s1.length() || k > s2.length()) return 0;

    int m{(int) s1.length()};
    int n{(int) s2.length()};

    if(dp[m][n][k] != -1) return dp[m][n][k];

    int ans{};
    if(s1[0] == s2[0]) {
        int ascaiiValue{(int) s1[0]};
        int option1{blessing(s1.substr(1), s2.substr(1), k - 1, dp)};
        if(option1 == 0 && k > 1) option1 = 0;
        else option1 += ascaiiValue;
        int option2{blessing(s1.substr(1), s2, k, dp)};
        int option3{blessing(s1,s2.substr(1), k, dp)};
        ans = max(option1, max(option2, option3));
    }else {
        int option1{blessing(s1.substr(1), s2, k, dp)};
        int option2{blessing(s1, s2.substr(1), k, dp)};
        ans = max(option1, option2);
    }
    dp[m][n][k] = ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int k;
        cin >> k;
        int dp[101][101][101];
        for(int i{}; i < 101; i++) {
            for(int j{}; j < 101; j++) {
                for(int k{}; k < 101;k++) dp[i][j][k] = -1;
            }
        }

        int ans {blessing(s1, s2, k, dp)};
        cout << ans << endl;
    }
}
