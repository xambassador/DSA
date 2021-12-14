#include<iostream>
#include<queue>
using std::cin;
using std::cout;
using std::endl;
using std::queue;
// BFS traversal

void print(bool** edges, int n, int sv, bool* visited) {
    queue<int> pendingVertex;
    pendingVertex.push(sv);
    visited[sv] = true;
    while(!pendingVertex.empty()) {
        int currentVertex{pendingVertex.front()};
        pendingVertex.pop();
        cout << currentVertex << " ";
        for(int i{}; i < n; i++) {
            if(i == currentVertex) continue;
            if(edges[currentVertex][i] == 1 && !visited[i]) {
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
    }
}

void printBFS(bool** edges, int n) {
    bool* visited {new bool[n]};
    for (int i{}; i < n; i++) visited[i] = false;
    for (int i{}; i < n; i++) {
        if (!visited[i]) print(edges, n, i, visited);
    }
    delete [] visited;
}

int main() {
    int n, e;
    cin >> n >> e;

    bool** edges {new bool*[n]};
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

    printBFS(edges, n);

    for (int i{}; i < n; i++) delete [] edges[i];
    delete [] edges;
}
