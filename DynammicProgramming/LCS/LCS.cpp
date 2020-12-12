#include<iostream>
#include<cstring>
// bruteforce approcah
int lcs(char* str1, char* str2) {
    // base case
    if(str1[0] == '\0' || str2[0] == '\0') {
        return 0;
    }

    if(str1[0] == str2[0]) {
        return lcs(str1+1, str2+1) + 1;
    }else {
        int option1 {lcs(str1, str2+1)};
        int option2 {lcs(str1+1, str2)};
        return std::max(option1, option2);
    }
}

// Memoization
int lcs2Help(char* s1, char* s2, int m, int n, int** dp) {
    if(m == 0 || n == 0) {
        return 0;
    }

    if(dp[m][n] > -1) {
        return dp[m][n];
    }

    int ans {};
    if(s1[0] == s2[0]) {
        ans = 1 + lcs2Help(s1+1,s2+1,m-1,n-1,dp);
    }else {
        int option1 = lcs2Help(s1,s2+1,m,n-1,dp);
        int option2 = lcs2Help(s1+1,s2,m-1,n,dp);
        ans = std::max(option1, option2);
    }
    dp[m][n] = ans;
    return ans;
}

int lcs2(char* s1, char* s2) {
    int m  = std::strlen(s1);
    int n  = std::strlen(s2);
    int** dp {new int*[m+1]};
    for(int i{0}; i<m+1; i++) {
        dp[i] = new int[n+1];
        for(int j {0}; j<n+1; j++) {
            dp[i][j] = -1;
        }
    }

    int ans {lcs2Help(s1,s2,m,n,dp)};

    for(int i{}; i<=m; i++) {
        delete [] dp[i];
    }

    delete [] dp;

    return ans;
}


int main(){ 
    char s1[100], s2[100];
    std::cin >> s1 >> s2;
    std::cout << lcs2(s1, s2) << std::endl;
    std::cout << lcs(s1, s2) << std::endl;
}   