#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

// 787. Cheapest Flights Within K Stops
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // dp stores the minimum cost to reach the city i from src
    vector<int> dp(n, INT_MAX);
    // the cost to reach src from src is 0
    dp[src] = 0;
    for (int i {}; i <= k; ++i) {
        vector<int> temp(dp);
        for (auto flight : flights) {
            // if the cost to reach city flight[0] from src is not INT_MAX
            if (dp[flight[0]] != INT_MAX) {
                // cost to reach city flight[1] from src is the minimum of
                // the current cost to reach city flight[1] from src and
                // the cost to reach city flight[0] from src plus the cost of the flight
                temp[flight[1]] = min(temp[flight[1]], dp[flight[0]] + flight[2]);
            }
        }
        dp = temp;
    }
    return dp[dst] == INT_MAX ? -1 : dp[dst];
}

// -----------------------------------------------------------------------------------------
int main () {
    int n, m, src, dst, k;
    cin >> n >> m;
    vector<vector<int>> flights(m, vector<int>(3));
    for (int i {}; i < m; ++i) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }
    cin >> src >> dst >> k;
    cout << findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}
