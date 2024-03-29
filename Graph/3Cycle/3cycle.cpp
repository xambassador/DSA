#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int cycle(bool** edges, int n, int m) {
    int cnt {};
    for (int i{}; i < n; i++) {
        for (int j{}; j < n; j++) {
            if (edges[i][j] && i != j) {
                for (int k{}; k < n; k++) {
                    if (edges[j][k] && j != k && k != i && edges[i][k]) cnt++;
                }
            }
        }
    }
    return cnt / 6;
}

int main() {
    int n, m;
    cin >> n >> m;

    bool** graph {new bool*[n]};
    for (int i{}; i < n; i++) {
        graph[i] = new bool[n];
        for (int j{}; j < n; j++) graph[i][j] = false;
    }

    for (int i{}; i < m; i++) {
        int sv, ev;
        cin >> sv >> ev;
        graph[sv][ev] = true;
        graph[ev][sv] = true;
    }

    int ans {cycle(graph, n, m)};
    cout << ans << endl;

    for (int i{}; i < n; i++) delete [] graph[i];
    delete [] graph;
}
