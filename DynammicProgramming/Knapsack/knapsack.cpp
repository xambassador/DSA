#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;

// Brute force
int knapsackHelp(int* w, int* v, int W, int start, int end) {
    if(W == 0) return 0;
    if(start > end) return 0;

    int ans {};
    if(w[start] <= W) {
        int option1{knapsackHelp(w, v, W - w[start], start + 1, end) + v[start]};
        int option2{knapsackHelp(w, v, W, start + 1, end)};
        ans = max(option1, option2);
    } else ans = knapsackHelp(w, v, W, start + 1, end);
    return ans;
}

// Top Down DP - Memoization
int kanpsackMemoization(int* w, int* v, int W, int start, int end, int** dp) {
    if(W == 0) return 0;
    if(start > end) return 0;
    if(dp[W][start] != -1) return dp[W][start];

    int ans {};
    if(w[start] <= W) {
        int option1{kanpsackMemoization(w, v, W - w[start], start + 1, end, dp) + v[start]};
        int option2{kanpsackMemoization(w, v, W, start + 1, end, dp)};
        ans = max(option1, option2);
    } else ans = kanpsackMemoization(w, v, W, start + 1, end, dp);
    dp[W][start] = ans;
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
    int dp[n + 1][maxWeight + 1];
    for(int i{}; i <= n; i++) {
        for(int j{}; j <= maxWeight; j++) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(weight[i - 1] <= maxWeight) dp[i][j] = max(value[i - 1] + dp[i - 1][maxWeight - weight[i - 1]], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][maxWeight];
}

int main() {
    int n, weights[101];
    cin >> n;
    for(int i{}; i < n; i++) cin >> weights[i];
    int values[101];
    for(int i{}; i < n; i++) cin >> values[i];
    int maxWeight{};
    cin >> maxWeight;
    int ans{knapsack(weights, values, n, maxWeight)};
    cout << ans << endl;
}
