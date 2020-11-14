#include<iostream>
using namespace std;
 

int maxSum(int** grid, int row, int col) {
    int dp[row][col];
    dp[0][0] = grid[0][0];
    for(int i = 1;i<row; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i = 1; i<col; i++) {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }

    for(int i =1; i<row; i++) {
        for(int j = 1; j<col; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + grid[i][j];
        }
    }

    cout << endl;
    for(int i =0;i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    cout << endl;

    return dp[row-1][col-1];
}


int main() {
    int n,m;
    cin >> n >> m;
    int** grid {new int*[n]};
    for(int i = 0; i<n; i++) {
        grid[i] = new int[m];
        for(int j = 0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = maxSum(grid,n,m);
    cout << ans << endl;

    for(int i=0; i<n; i++) {
        delete [] grid[i];
    }

    delete [] grid;
}
