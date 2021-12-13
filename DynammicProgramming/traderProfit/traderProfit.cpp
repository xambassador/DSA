#include<iostream>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::max;

int maxProfit(int* arr, int n, int k, bool isTransactionOngoing) {
    if (n == 0) return 0;

    // ignore stock
    int option1{maxProfit(arr + 1, n - 1, k, isTransactionOngoing)};
    int option2{};
    int option3{};
    // i can buy stock that day
    if (isTransactionOngoing) {
        // becuase transaction is ingoing, i can sell only
        option2 = maxProfit(arr + 1, n - 1, k - 1, false) + arr[0];
    } else {
        if (k > 0) option3 = maxProfit(arr + 1, n - 1, k, true) - arr[0];
    }
    int ans{max(option1, max(option2, option3))};
    return ans;
}

int maxProfit(int* arr, int n, int k, bool isTransactionOngoing, int*** dp) {
    if (n == 0) return 0;
    if (dp[n][k][isTransactionOngoing] != -1) return dp[n][k][isTransactionOngoing];

    // ignore stock
    int option1{maxProfit(arr + 1, n - 1, k, isTransactionOngoing, dp)};
    int option2{};
    int option3{};
    // i can buy stock that day
    if (isTransactionOngoing) {
        // becuase transaction is ingoing, i can sell only
        option2 = maxProfit(arr + 1, n - 1, k - 1, false, dp) + arr[0];
    } else {
        if (k > 0) option3 = maxProfit(arr + 1, n - 1, k, true, dp) - arr[0];
    }
    int ans{max(option1, max(option2, option3))};
    dp[n][k][isTransactionOngoing] = ans;
    return ans;
}

int main () {
    int q;
    cin >> q;
    while(q--) {
        int k, n, arr[n];
        cin >> k >> n;
        for(int i{}; i < n; i++) cin >> arr[i];
        int*** dp {new int**[n + 1]};
        for(int i{}; i < n + 1; i++) {
            dp[i] = new int*[k + 1];
            for(int j{}; j < k + 1; j++) {
                dp[i][j] = new int[2];
                for(int k{}; k < 2; k++) dp[i][j][k] = -1;
            }
        }

        int ans {maxProfit(arr, n, k, false, dp)};
        cout << ans << endl;
        for(int i{}; i < n + 1; i++) {
            for (int j{}; j < k + 1; j++) delete [] dp[i][j];
            delete [] dp[i];
        }
        delete [] dp;
    }
}
