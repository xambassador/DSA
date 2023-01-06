#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
// -----------------------------------------------------------------------------

void dfs(vector<vector<char>>& grid, int i, int j) {
    // If we are out of bounds or if the current cell is '0' we return
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0') return;
    // Mark the current cell as '0'
    grid[i][j] = '0';
    // Call the dfs function on all the adjacent cells (up, down, left, right)
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

// -----------------------------------------------------------------------------
int numIslands(vector<vector<char>>& grid) {
    int numberOfIslands {};
    // Iterate through the grid and if we find a '1' we increment the number of islands
    // and then we call the dfs function to mark all the adjacent '1's as '0's
    for (int i {}; i < grid.size(); i++) {
        for (int j {}; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                numberOfIslands++;
                dfs(grid, i, j);
            }
        }
    }
    return numberOfIslands;
}

// -----------------------------------------------------------------------------
int main () {
    vector<vector<char>> grid {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << numIslands(grid) << endl;
    return 0;
}
