#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

void dfs(vector<vector<int>>& grid, int x, int y, int end_x, int end_y, int totalEmptyCells, vector<vector<bool>>& visited, int& res) {
    // If we reach the end point,
    if (x == end_x && y == end_y) {
        // If we have visited all the totalEmptyCells cells, we increment the result
        if (totalEmptyCells == 0) res++;
        return;
    }
    // We try to go to all the possible directions
    int m {(int)grid.size()}, n {(int)grid[0].size()};

    // We check if we can go to the left cell and if we haven't visited it yet and if it is not a obstacle (-1)
    if (x - 1 >= 0 && grid[x - 1][y] != -1 && !visited[x - 1][y]) {
        // We mark the cell as visited
        visited[x - 1][y] = true;
        // We call the dfs function with the new coordinates
        dfs(grid, x - 1, y, end_x, end_y, totalEmptyCells - 1, visited, res);
        // We mark the cell as unvisited again so we can use it in other paths
        visited[x - 1][y] = false;
    }

    // We check if we can go to the right cell and if we haven't visited it yet and if it is not a obstacle (-1)
    if (x + 1 < m && grid[x + 1][y] != -1 && !visited[x + 1][y]) {
        // We mark the cell as visited
        visited[x + 1][y] = true;
        // We call the dfs function with the new coordinates
        dfs(grid, x + 1, y, end_x, end_y, totalEmptyCells - 1, visited, res);
        // We mark the cell as unvisited again so we can use it in other paths
        visited[x + 1][y] = false;
    }

    // We check if we can go to the up cell and if we haven't visited it yet and if it is not a obstacle (-1)
    if (y - 1 >= 0 && grid[x][y - 1] != -1 && !visited[x][y - 1]) {
        // We mark the cell as visited
        visited[x][y - 1] = true;
        // We call the dfs function with the new coordinates
        dfs(grid, x, y - 1, end_x, end_y, totalEmptyCells - 1, visited, res);
        // We mark the cell as unvisited again so we can use it in other paths
        visited[x][y - 1] = false;
    }

    // We check if we can go to the down cell and if we haven't visited it yet and if it is not a obstacle (-1)
    if (y + 1 < n && grid[x][y + 1] != -1 && !visited[x][y + 1]) {
        // We mark the cell as visited
        visited[x][y + 1] = true;
        // We call the dfs function with the new coordinates
        dfs(grid, x, y + 1, end_x, end_y, totalEmptyCells - 1, visited, res);
        // We mark the cell as unvisited again so we can use it in other paths
        visited[x][y + 1] = false;
    }
}

int uniquePathsIII(vector<vector<int>>& grid) {
    // We find the start and end points and the number of empty cells.
    int row {(int)grid.size()};
    int col {(int)grid[0].size()};
    int start_x {}, start_y {};
    int end_x {}, end_y {};
    int totalEmptyCells {1};
    for (int i{}; i < row; i++) {
        for (int j{}; j < col; j++) {
            // Here find the start point, we save its coordinates
            if (grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            }

            // Here find the end point, we save its coordinates
            if (grid[i][j] == 2) {
                end_x = i;
                end_y = j;
            }

            // Here we count the number of totalEmptyCells cells
            if (grid[i][j] == 0) {
                totalEmptyCells++;
            }
        }
    }
    int result {};
    // 2D vector to mark the visited cells
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    visited[start_x][start_y] = true;
    dfs(grid, start_x, start_y, end_x, end_y, totalEmptyCells, visited, result);
    return result;
}

int main () {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cin >> grid[i][j];
    }
    cout << uniquePathsIII(grid) << endl;
    return 0;
}
