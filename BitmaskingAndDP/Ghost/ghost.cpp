#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool tmp[1 << 22];
long long dp[1 << 22];
vector<int> submask[22];

long long solve(int mask, int n) {
    if (mask == (1 << (n + 1)) - 2) return 1;
    if (tmp[mask]) return dp[mask];

    tmp[mask] = 1;
    long long& ans {dp[mask]};
    ans = 0;
    int x;
    for (int i{1}; i <= n; i++) {
        if (!(mask & (1 << i))) {
            bool flag {true};
            for (int j{}; j<submask[i].size(); j++) {
                x = submask[i][j];
                if (!(mask & (1 << x))) flag = false;
            }
            if (flag) ans += solve((mask | (1 << i)), n);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i{1}; i <= 20; i++) {
        for (int j{i - 1}; j >= 1; j--) if ((i & j) == j) submask[i].push_back(j);
    }
    cout << solve(0,n) << endl;
}
