#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


int dp[105][1 << 12];

int findTouches(int pos, int mask, vector<string>& arr) {
    if (! (mask & (mask - 1)) && mask) return 0;

    if (pos == -1 || mask == 0) return 100000;

    if (dp[pos][mask]) return dp[pos][mask];

    int newMask1 {};
    int newMask2 {};
    int touches {};

    for (int i{}; i<arr.size(); i++) {
        if ((mask >> i) & 1) {
            touches++;
            if (arr[i][pos] == '0') newMask1 |= (1 << i);
            else newMask2 |= (1 << i);
        }
    }

    int ans1 {findTouches(pos - 1, newMask1, arr)};
    int ans2 {findTouches(pos - 1, newMask2, arr)};
    int ans3 {findTouches(pos - 1, mask, arr)};

    dp[pos][mask] = min(ans1+ans2+touches, ans3);
    return dp[pos][mask];
}


int minimumTouchesRequired(int n, vector<string> v) {
    return findTouches(v[0].size() - 1,(1 << n) - 1, v);
}