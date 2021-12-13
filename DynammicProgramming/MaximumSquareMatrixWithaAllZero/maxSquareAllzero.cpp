#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::min;

int maxSqMatrix(int** arr, int row, int col) {
    int dp[row][col];
    for(int i{}; i < row; i++) {
        if(arr[i][0] == 1) dp[i][0] = 0;
        else dp[i][0] = 1;
    }

    for(int i{}; i < col ; i++) {
        if(arr[0][i] == 1) dp[0][i] = 0;
        else dp[0][i] = 1;
    }

    for(int i{1}; i < row; i++) {
        for(int j{1}; j < col; j++) {
            if(arr[i][j] == 1) dp[i][j] = 0;
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }

    int max{};
    for(int i{}; i < row; i++) {
        for(int j{}; j < col; j++) {
            if(max < dp[i][j]) max = dp[i][j];
        }
    }
    return max;
}

int main() {
    int n, m;
    cin >> n >> m;
    int** arr{new int*[n]};
    for(int i{}; i < n; i++) {
        arr[i] = new int[m];
        for(int j{}; j < m; j++) cin >> arr[i][j];
    }
    int ans{maxSqMatrix(arr, n, m)};
    cout << ans << endl;
    for(int i{}; i < n; i++) delete [] arr[i];
    delete [] arr;
}
