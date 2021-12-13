#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::min;

int findTouches(int pos, int mask, vector<string>& arr, int** dp) {
    if ((mask & (mask - 1)) == 0) return 0;

    if (pos < 0) return 100000;

    if (dp[pos][mask] != INT_MAX) return dp[pos][mask];

    int newMask1 {}, newMask2 {}, touches {};

    for (int i{}; i < arr.size(); i++) {
        if ((mask & (1 << i))) {
            touches++;
            if (arr[i][pos] == '0') newMask1 |= (1 << i);
            else newMask2 |= (1 << i);
        }
    }

    int ans1 {findTouches(pos - 1, newMask1, arr,dp)};
    int ans2 {findTouches(pos - 1, newMask2, arr,dp)};
    int ans3 {findTouches(pos - 1, mask, arr,dp)};

    dp[pos][mask] = min(ans1+ans2+touches, ans3);
    return dp[pos][mask];
}

int minimumTouchesRequired(int n, vector<string> v) {
    int** dp {new int*[v[0].size()]};
    for (int i{}; i < v[0].size(); i++) {
        dp[i] = new int[1 << (n+1)];
        for (int j{}; j < (1<<(n+1)); j++) dp[i][j] = INT_MAX;
    }
    int ans {findTouches(v[0].size() - 1,(1 << n) - 1, v, dp)};
    for (int i{}; i < n; i++) delete [] dp[i];
    delete [] dp;
    return ans;
}
