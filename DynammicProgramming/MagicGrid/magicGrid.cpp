#include<iostream>
using namespace std;
 

int dp[1000][1000];


/* Simple Brute force*/
int bruteForce(int** grid, int srow, int scol, int row, int col) {
    // Here row = n-1 , col = m-1
    // If i reach at either [row-1][col] (just above the destination) or [row][col-1] (just left of destination)
    // I return 1
    if((srow == row-1 && scol == col) || (srow == row && scol == col-1)) {
        return 1;
    }

    // Now if i cross grid
    if(srow > row || scol > col) {
        return INT_MAX;
    }

    // call recursion for ans1
    int ans1 {bruteForce(grid, srow+1, scol,row,col)};

    // If i got INT_MAX, that means i cross the grid, so i avoid to do substraction
    if(ans1 != INT_MAX) {
        int tmp {grid[srow+1][scol]};
        if(tmp < 0) {
            tmp = abs(tmp);
            ans1 = ans1 + tmp;
        }else {
            ans1 = ans1 - tmp;
        }
    }
    if(ans1 <= 0) ans1 = 1;

    int ans2 {bruteForce(grid,srow,scol+1,row,col)};
    if(ans2 != INT_MAX) {
        int t {grid[srow][scol+1]};
        if(t < 0) {
            t = abs(t);
            ans2 = ans2 + t;
        }else {
            ans2 = ans2 - t;
        }
    }
    if(ans2 <= 0) ans2 = 1;

    return min(ans1,ans2);
}



/* Top down DP*/
int help(int** grid, int srow, int scol, int row, int col) {
    // Here row = n-1 , col = m-1
    // If i reach at either [row-1][col] (just above the destination) or [row][col-1] (just left of destination)
    // I return 1
    if((srow == row-1 && scol == col) || (srow == row && scol == col-1)) {
        return 1;
    }

    // Now if i cross grid
    if(srow > row || scol > col) {
        return INT_MAX;
    }

    // before do anything, first check if i already calculate for this cell or not
    if(dp[srow][scol] != -1) {
        return dp[srow][scol];
    }

    // call recursion for ans1
    int ans1 {help(grid, srow+1, scol,row,col)};

    // If i got INT_MAX, that means i cross the grid, so i avoid to do substraction
    if(ans1 != INT_MAX) {
        int tmp {grid[srow+1][scol]};
        if(tmp < 0) {
            tmp = abs(tmp);
            ans1 = ans1 + tmp;
        }else {
            ans1 = ans1 - tmp;
        }
    }
    if(ans1 <= 0) ans1 = 1;

    int ans2 {help(grid,srow,scol+1,row,col)};
    if(ans2 != INT_MAX) {
        int t {grid[srow][scol+1]};
        if(t < 0) {
            t = abs(t);
            ans2 = ans2 + t;
        }else {
            ans2 = ans2 - t;
        }
    }
    if(ans2 <= 0) ans2 = 1;

    // save my answer
    dp[srow][scol] = min(ans1,ans2);

    return dp[srow][scol];
}

/* Bottom up DP*/
int help_dp(int** grid, int srow, int scol, int row, int col) {
    int dp[row][col];

    dp[row-1][col-1] = 1;
    dp[row-1][col-2] = 1;
    dp[row-2][col-1] = 1;

    for(int i{col-3};i>=0; --i) {
        int tmpAns = 1;
        if(grid[row-1][i+1] < 0) {
            tmpAns = dp[row-1][i+1] + abs(grid[row-1][i+1]);
        }else {
            tmpAns = dp[row-1][i+1] - grid[row-1][i+1];
        }
        if(tmpAns <= 0) tmpAns = 1;
        dp[row-1][i] = tmpAns;
    }

    for(int i{row-3}; i>=0; --i) {
        int tmpAns = 1;
        if(grid[i][col-1] < 0) {
            tmpAns = dp[i+1][col-1] + abs(grid[i+1][col-1]);
        }else {
            tmpAns = dp[i+1][col-1] - grid[i+1][col-1];
        }
        if(tmpAns <= 0) tmpAns = 1;
        dp[i][col-1] = tmpAns; 
    }

    for(int r{row-2}; r>=0; --r) {
        for(int c{col-2}; c>=0; --c){
            int tmpAns1 = 1;
            int tmpAns2 = 1;

            tmpAns1 = dp[r+1][c] - grid[r+1][c];
            tmpAns2 = dp[r][c+1] - grid[r][c+1];

            if(tmpAns1 <= 0) {
                tmpAns1 = 1;
            }
            if(tmpAns2 <= 0) {
                tmpAns2 = 1;
            }

            dp[r][c] = min(tmpAns1,tmpAns2);
        }
    }

    return dp[0][0];
}



int getMinimumStrength(int** grid, int n, int m) {
    for(int i{}; i<n; i++) {
        for(int j{}; j<m; j++) {
            dp[i][j] = -1;
        }
    }
    dp[n-1][m-1] = 1;
    dp[n-2][m-1] = 1;
    dp[n-1][m-2] = 1;

	return help(grid, 0,0,n-1,m-1);
}


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int **grid = new int *[n];

        for (int i = 0; i < n; ++i) {
            grid[i] = new int[m];
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        cout << getMinimumStrength(grid, n, m) << "\n";
        cout << bruteForce(grid,0,0,n-1,m-1) << "\n";
        cout << help_dp(grid,0,0,n,m) << "\n";

        for (int i = 0; i < n; ++i) {
            delete[] grid[i];
        }

        delete[] grid;
    }
}