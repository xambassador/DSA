#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int dfs(int m, int n, int i, int j) {
    if (i == m - 1 && j == n - 1) return 1;
    int count {};
    if (i < m - 1) count += dfs(m, n, i + 1, j);
    if (j < n - 1) count += dfs(m, n, i, j + 1);
    return count;
}

// int uniquePaths(int m, int n) {
//     if (m == 1 || n == 1) return 1;
//     return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
// }

int uniquePathsDp(int m, int n) {
    if (m == 1 || n == 1) return 1;
    int dp[m][n];
    for (int i{}; i < m; i++) dp[i][0] = 1;
    for (int j{}; j < n; j++) dp[0][j] = 1;
    for (int i{1}; i < m; i++) {
        for (int j{1}; j < n; j++) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    return dp[m - 1][n - 1];
}

int uniquePaths(int m, int n) {
    // if (m == 1 || n == 1) {
    //     return 1;
    // }
    // return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    return dfs(m, n, 0, 0);
}

int main () {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
}
