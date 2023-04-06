#include <vector>
using std::vector;

bool dfs(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;

    if (grid[x][y] == 1 || visit[x][y]) return true;

    visit[x][y] = true;
    bool isClosed {true};
    vector<int> dirx {0, 1, 0, -1};
    vector<int> diry {-1, 0, 1, 0};

    for (int i{}; i < 4; i++) {
        int r {x + dirx[i]};
        int c {y + diry[i]};
        if (!dfs(r, c, m, n, grid, visit)) {
            isClosed = false;
        }
    }

    return isClosed;
}

// https://leetcode.com/problems/number-of-closed-islands/
int closedIsland(vector<vector<int>>& grid) {
    int m {(int)grid.size()};
    int n {(int)grid[0].size()};
    int count {};
    vector<vector<bool>> visit(m, vector<bool>(n));
    for (int i{}; i < m; i++) {
        for (int j{}; j < n; j++) {
            if (grid[i][j] == 0 && !visit[i][j] && dfs(i, j, m, n, grid, visit)) {
                count++;
            }
        }
    }
    return count;
}
