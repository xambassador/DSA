#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int getMin(int* arr, int n) {
    int dp[n];
    // every student get at least 1 chocolate
    for(int i{}; i < n; i++) dp[i] = 1;
    // go from left to right
    for(int i{1}; i < n; i++) {
        if(arr[i] > arr[i - 1]) dp[i] = 1 + dp[i - 1];
    }
    // go from right to left
    for(int i{n - 2}; i>=0; i--) {
        if(arr[i] >  arr[i + 1] && dp[i] <= dp[i + 1]) dp[i] = 1 + dp[i + 1];
    }
    int sum {0};
    for(int i{}; i < n; i++) sum += dp[i];
    return sum;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i{}; i < n; i++) cin >> arr[i];
    int ans{getMin(arr, n)};
    cout << ans << endl;
}
