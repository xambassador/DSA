#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::boolalpha;

int xdir[4]{1, -1, 0, 0};
int ydir[4]{0 ,0, 1, -1};

bool isSafe(vector<vector<char> >& board, int rows, int cols, int i, int j, char currentChar) {
    if (i >= 0 && j >= 0 && i < rows && j < cols && board[i][j] == currentChar) return true;
    return false;
}

bool helper(vector<vector<char> >& board, int rows, int cols, int i, int j, int fromX, int fromY, char currentChar, vector<vector<bool> >& visited) {
    if (i > rows || j > cols) return false;
    if (visited[i][j]) return true;
    if (board[i][j] != currentChar) return false;
    visited[i][j] = true;
    for (int k{}; k < 4; k++) {
        int nextI{i + xdir[k]};
        int nextJ{j + ydir[k]};
        if (isSafe(board, rows, cols, nextI, nextJ, currentChar) && (nextI != fromX || nextJ != fromY)) {
            if (helper(board, rows, cols, nextI, nextJ, i, j, currentChar, visited)) return true;
        }
    }
    return false;
}

bool hasCycle(vector<vector<char> >& board, int rows, int cols) {
    vector<vector<bool> > visited(rows, vector<bool>(cols));
    for (int i{}; i < rows; i++) {
        for (int j{}; j < cols; j++) visited[i][j] = false;
    }

    for (int i{}; i < rows; i++) {
        for (int j{}; j < cols; j++) {
            if (!visited[i][j]) {
                char current{board[i][j]};
                if (helper(board, rows, cols, i, j, -1, -1, current, visited)) return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));
    for (int i{}; i < n; i++) {
        for (int j{}; j < m; j++) cin >> board[i][j];
    }
    bool ans{hasCycle(board, n, m)};
    cout << boolalpha << ans << endl;
}
