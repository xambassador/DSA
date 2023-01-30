#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

// Leetcode 1137. N-th Tribonacci Number

// Time Complexity: O(3^n)
// Space Complexity: O(n)
int tribonacci_rec(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    return tribonacci_rec(n - 1) + tribonacci_rec(n - 2) + tribonacci_rec(n - 3);
}

// Time Complexity: O(n)
// Space Complexity: O(n)
int tribonacci_dp(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (n == 3) return 2;
    int dp[38] {};
    dp[0] = 0;
    dp[1] = dp[2] = 1;
    dp[3] = 2;
    for (int i{4}; i < 38; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n];
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    int a {}, b {1}, c {1};
    for (int i {3}; i <= n; ++i) {
        int d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    cout << tribonacci(n) << endl;
    return 0;
}
