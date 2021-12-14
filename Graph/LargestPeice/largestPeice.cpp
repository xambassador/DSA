#include<iostream>
#include<vector>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int xdir[]{-1, 1, 0, 0};
int ydir[]{0, 0, 1, -1};

bool isSafe(vector<vector<int> >& cake, int rows, int i, int j, vector<vector<bool> >& visited) {
    if (i>=0 && j>=0 && i<rows && j<rows && cake[i][j] == 1 && !visited[i][j]) return true;
    return false;
}

void dfs(vector<vector<int> >& cake, int rows, int i, int j, vector<vector<bool> >& visited, int& cnt) {
    visited[i][j] = true;
    for(int k{}; k < 4; k++) {
        if(isSafe(cake, rows, i + xdir[k], j + ydir[k], visited)) {
            cnt++;
            dfs(cake, rows, i + xdir[k], j + ydir[k], visited, cnt);
        }
    }
}

int getLargestPeice(vector<vector<int> >& cake,int rows) {
    vector<vector<bool> > visited(rows, vector<bool>(rows));
    for(int i{}; i < rows; i++) {
        for (int j{}; j < rows;j++) visited[i][j] = false;
    }

    // first find 1 in cake
    int ans {};
    for (int i{}; i < rows; i++) {
        for (int j{}; j < rows; j++) {
            if (cake[i][j] == 1 && !visited[i][j]) {
                int cnt{1};
                dfs(cake, rows, i, j, visited, cnt);
                if (ans < cnt) ans = cnt;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > cake(n, vector<int>(n));
    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) cin >> cake[i][j];
    }
    int ans {getLargestPeice(cake,n)};
    cout << ans << endl;
}
