#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void DFS(bool** edges, int& n, int& sv, bool* visited) {
    visited[sv] = true;
    for (int i{}; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] && !visited[i]) DFS(edges, n, i, visited);
    }
}

int island(bool** edges, int n) {
    bool* visited{new bool[n]};
    for (int i{}; i < n; i++) visited[i] = false;
    int cnt {};
    for (int i{}; i < n; i++) {
        if (!visited[i]) {
            DFS(edges, n, i, visited);
            cnt++;
        }
    }
    delete [] visited;
    return cnt;
}

int main() {
    int v, e;
    cin >> v >> e;

    bool** edges{new bool*[v]};
    for (int i{}; i < v; i++) {
        edges[i] = new bool[v];
        for (int j{}; j < v; j++) edges[i][j] = false;
    }

    for (int i{}; i < e; i++) {
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }

    int ans{island(edges, v)};
    cout << ans << endl;

    for (int i{}; i < v; i++) delete [] edges[i];
    delete [] edges;
}
