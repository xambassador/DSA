#include<iostream>
#include<map>
#include<vector>
#include<queue>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::map;

// BFS traversal

void BFS(bool** edges, int n, int& startVertex, int& endVertex) {
    bool* visited{new bool[n]()};
    for (int i{}; i < n; i++) visited[i] = false;

    queue<int> pendingVertex;
    map<int,int> path;
    pendingVertex.push(startVertex);
    visited[startVertex] = true;

    while(!pendingVertex.empty()) {
        int currentVertex = pendingVertex.front();
        if (currentVertex == endVertex) break;
        for(int i{}; i < n; i++) {
            if(i == currentVertex) continue;
            if(edges[currentVertex][i] && !visited[i]) {
                path[i] = currentVertex;
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
        pendingVertex.pop();
        if (pendingVertex.empty()) return;
    }

    int i{endVertex};
    cout << i << " ";
    while(i != startVertex) {
        cout << path[i]  << " ";
        i = path[i];
    }
    delete visited;
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

    BFS(edges,n,startVertex,endVertex);

    for (int i{}; i < n; i++) delete [] edges[i];
    delete [] edges;
}
