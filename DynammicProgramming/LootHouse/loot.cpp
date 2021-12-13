#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::max;

int dp[100000];

int help(int* arr, int n, int start) {
    if(start > n) return 0;

    if(start == n) {
        dp[start] = arr[start];
        return arr[start];
    }

    if(dp[start] > 0) return dp[start];

    int myAns{};
    int LootCurrentHouse{arr[start] + help(arr, n, start + 2)};
    int NotLootCurrentHouse{help(arr, n, start + 1)};
    myAns = max(LootCurrentHouse, NotLootCurrentHouse);
    dp[start] = myAns;
    return myAns;
}

/* Bottom  up dp*/

int maxLoot(int* arr, int n) {
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    if(n == 2) return max(arr[0], arr[1]);
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for(int i{2}; i < n; i++) {
        // if i loot current house,
        int includeCurrHouse{arr[i] + dp[i - 2]};

        // if i dont loot current house
        int excludeCurrentHouse{dp[i - 1]};

        // final answer is maximum both of 2
        dp[i] = max(includeCurrHouse, excludeCurrentHouse);
    }
    return dp[n - 1];
}

int maxMoneyLooted(int* arr, int n) {
    memset(dp, 0, n * sizeof(int));
    return help(arr, n - 1, 0);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i{}; i < n; i++) cin >> arr[i];
    cout << maxMoneyLooted(arr, n) << endl;
    cout << maxLoot(arr, n) << endl;
}
