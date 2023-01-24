#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

int snakesAndLadders(vector<vector<int>>& board) {
    int n {(int)board.size()};
    vector<int> moves(n * n + 1);
    int i {n - 1}, j {}, even {};
    for (int k{1}; k <= n * n; k++) {
        moves[k] = board[i][j];
        if (even % 2 == 0) j++;
        else j--;

        if (j == n) {
            i--;
            j--;
            even++;
        } else if (j == -1) {
            i--;
            j++;
            even++;
        }
    }
    vector<bool> visited(n * n + 1);
    vector<int> queue;
    queue.push_back(1);
    visited[1] = true;
    int steps {};
    while (!queue.empty()) {
        int size {(int)queue.size()};
        for (int i{}; i < size; i++) {
            int curr {queue[i]};
            if (curr == n * n) return steps;
            for (int j{1}; j <= 6; j++) {
                int next{curr + j};
                if (next > n * n) break;
                if (moves[next] != -1) next = moves[next];
                if (!visited[next]) {
                    queue.push_back(next);
                    visited[next] = true;
                }
            }
        }
        queue.erase(queue.begin(), queue.begin() + size);
        steps++;
    }
    return -1;
}

// -----------------------------------------------------------------------------------------
int main () {
    int n {};
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cout << snakesAndLadders(board) << endl;
    return 0;
}
