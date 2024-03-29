#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

void DFS(bool** edges, int n, bool* visited, int sv) {
    visited[sv] = true;
    for (int i{}; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] && !visited[i]) DFS(edges, n, visited, i);
    }
}

bool isConnected(bool** edges, int n) {
    bool* visited{new bool[n]};
    for(int i{}; i < n; i++) visited[i] = false;
    DFS(edges, n, visited, 0);
    for (int i{}; i < n; i++) if (!visited[i]) return false;
    delete [] visited;
    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    bool** edges{new bool*[n]};
    for (int i{}; i < n; i++) {
        edges[i] = new bool[n];
        for (int j{}; j < n; j++) edges[i][j] = false;
    }

    for(int i{}; i < e; i++) {
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }

    cout << boolalpha << isConnected(edges, n) << endl;

    for(int i{}; i < n; i++) delete [] edges[i];
    delete [] edges;
}
