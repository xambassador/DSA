#include <iostream>
#include <vector>
#include <algorithm>
using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int minCostClimbingStairs(vector<int>& cost) {
    int n {(int)cost.size()};
    vector<int> dp(n + 1, 0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i{2}; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + (i == n ? 0 : cost[i]);
    }
    return dp[n];
}

// -----------------------------------------------------------------------------
int main () {
    vector<int> cost {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}
