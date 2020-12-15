#include<iostream>


int blessing(std::string s1, std::string s2, int k, int dp[][101][101]) {
    if(k == 0) {
        return 0;
    }

    if(k > s1.length() || k > s2.length()) {
        return 0;
    }

    int m {(int)s1.length()};
    int n {(int)s2.length()};

    if(dp[m][n][k] != -1) {
        return dp[m][n][k];
    }

    int ans {};
    if(s1[0] == s2[0]) {
        int ascaiiValue {(int)s1[0]};
        int option1 {blessing(s1.substr(1), s2.substr(1), k-1,dp)};
        if(option1 == 0 && k > 1) {
            option1 = 0;
        }else {
            option1 += ascaiiValue;
        }
        int option2 {blessing(s1.substr(1), s2, k,dp)};
        int option3 {blessing(s1,s2.substr(1), k,dp)};
        ans = std::max(option1, std::max(option2, option3));
    }else {
        int option1 {blessing(s1.substr(1), s2, k, dp)};
        int option2 {blessing(s1, s2.substr(1), k, dp)};
        ans = std::max(option1, option2);
    }
    dp[m][n][k] = ans;
    return ans;
}


int main() {
    int t;
    std::cin >> t;
    while(t--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        int k;
        std::cin >> k;

        // int*** dp {new int**[101]};
        // for(int i{}; i<101; i++) {
        //     dp[i] = new int*[101];
        //     for(int j{}; j<101; j++) {
        //         dp[i][j] = new int[101];
        //         for(int k{}; k<101; k++) {
        //             dp[i][j][k] = -1;
        //         }
        //     }
        // }

        int dp[101][101][101];
        for(int i{}; i<101; i++) {
            for(int j{}; j<101; j++) {
                for(int k{}; k<101;k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        int ans {blessing(s1,s2,k,dp)};
        std::cout << ans << std::endl;
    }
}