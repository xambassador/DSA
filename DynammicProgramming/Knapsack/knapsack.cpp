#include<iostream>

// Brute force
int knapsackHelp(int* w, int* v, int W, int start, int end) {
    if(W == 0) {
        return 0;
    }

    if(start > end) {
        return 0;
    }

    int ans {};
    if(w[start] <= W) {
        int option1 {knapsackHelp(w,v,W-w[start], start+1, end) + v[start]};
        int option2 {knapsackHelp(w,v,W,start+1, end)};
        ans = std::max(option1, option2);
    }else {
        ans = knapsackHelp(w,v,W,start+1,end);
    }
    return ans;
}


// Top Down DP - Memoization
int kanpsackMemoization(int* w, int* v,int W, int start, int end, int** dp) {
    if(W == 0) {
        return 0;
    }

    if(start > end) {
        return 0;
    }

    if(dp[W][start] != -1) {
        return dp[W][start];
    }

    int ans {};
    if(w[start] <= W) {
        int option1 {kanpsackMemoization(w,v,W-w[start], start+1, end, dp) + v[start]};
        int option2 {kanpsackMemoization(w,v,W,start+1, end, dp)};
        ans = std::max(option1, option2);
    }else {
        ans = kanpsackMemoization(w,v,W,start+1,end, dp);
    }
    dp[W][start] = ans;
    return ans;
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
    // return knapsackHelp(weight,value,maxWeight,0,n-1);
    // int** dp {new int*[maxWeight+1]};
    // for(int i{}; i<=maxWeight; i++) {
    //     dp[i] = new int[n+1];
    //     for(int j{}; j<=n; j++) {
    //         dp[i][j] = -1;
    //     }
    // }
    
    // int ans {kanpsackMemoization(weight,value,maxWeight,0,n,dp)};

    // for(int i{}; i<=maxWeight; i++) {
    //     delete [] dp[i];
    // }

    // delete [] dp;
    // return ans;

    // Bottom Up dp

    int dp[n+1][maxWeight+1];
    for(int i{}; i<=n; i++) {
        for(int j{}; j<=maxWeight; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }

            else if(weight[i-1] <= maxWeight) {
                dp[i][j] = std::max(value[i-1] + dp[i-1][maxWeight - weight[i-1]], dp[i-1][j]);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][maxWeight];
}


int main() {
    int n;
    std::cin >> n;
    int weights[101];
    for(int i{}; i<n; i++) {
        std::cin >> weights[i];
    }
    int values[101];
    for(int i{}; i<n; i++) {
        std::cin >> values[i];
    }
    int maxWeight{};
    std::cin >> maxWeight;
    
    int ans {knapsack(weights,values, n, maxWeight)};
    std::cout << ans << std::endl;
}