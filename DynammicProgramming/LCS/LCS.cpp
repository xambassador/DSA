#include<iostream>
#include<string>

int lcs(std::string s, std::string t) {
    int m {(int)s.length()};
    int n {(int)t.length()};
    int** dp {new int*[m+1]};
    for(int i{}; i<=m; i++) {
        dp[i] = new int[n+1];
    }

    for(int i{}; i<=m; i++){
        dp[i][0] = 0;
    }

    for(int i{}; i<=n; i++) {
        dp[0][i] = 0;
    }

    for(int i{1}; i<=m; i++) {
        for(int j{1}; j<=n; j++) {
            if(s[m-i] == t[n-j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int ans {dp[m][n]};
    for(int i{}; i<=m; i++) {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    int ans {lcs(s,t)};
    std::cout << ans << std::endl;
}