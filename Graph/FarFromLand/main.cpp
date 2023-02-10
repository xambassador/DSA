#include <iostream>
#include <vector>
#include <algorithm>
using std::min;
using std::max;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


int maxDistance(vector<vector<int>>& grid) {
    int rows {(int)grid.size()};
    int cols {(int)grid[0].size()};
    int result {};

    for (int i{}; i < rows; i++) {
        for (int j{}; j < cols; j++) {
            // If it's land, skip it
            if (grid[i][j] == 1) continue;
            // If it's water, set it to max value (here use 1111, as constraint says max length is 100).
            grid[i][j] = 1001;
            // If it's not the first row, update the value to min of current value and the value of the cell above + 1.
            if (i > 0) grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
            // If it's not the first column, update the value to min of current value and the value of the cell on the left + 1.
            if (j > 0) grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
        }
    }

    for (int i{rows - 1}; i >= 0; i--) {
        for (int j{cols - 1}; j >= 0; j--) {
            // If it's land, skip it
            if (grid[i][j] == 1) continue;
            // If i is not the last row, update the value to min of current value and the value of the cell below + 1.
            if (i < rows - 1) grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
            // If j is not the last column, update the value to min of current value and the value of the cell on the right + 1.
            if (j < cols - 1) grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
            // Update the result to max of current result and the value of the cell.
            result = max(result, grid[i][j]);
        }
    }

    if (result == 1001) return -1;
    return result - 1;
}
