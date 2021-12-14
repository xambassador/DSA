#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

bool DFS(bool** edges, int n, int& startVertex, int& endVertex, bool* visited) {
    if (edges[startVertex][endVertex]) return true;
    visited[startVertex] = true;
    for (int i{}; i < n; i++) {
        if (startVertex == i) continue;
        if (edges[startVertex][i] && !visited[i]) {
            bool ans {DFS(edges, n, i, endVertex, visited)};
            if (ans) return ans;
            else continue;
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;

    bool** edges{new bool*[n]};
    for (int i{}; i < n; i++) {
        edges[i] = new bool[n];
        for (int j{}; j < n; j++) edges[i][j] = false;
    }

    for (int i{}; i < e; i++) {
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }

    int startVertex, endVertex;
    cin >> startVertex >> endVertex;

    bool* visited {new bool[n]};
    for (int i{}; i < n; i++) visited[i] = false;

    bool ans{DFS(edges, n, startVertex, endVertex, visited)};
    cout << boolalpha << ans << endl;
}
