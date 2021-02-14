#include<iostream>
#include<map>
#include<vector>
#include<queue>

// BFS traversal

void BFS(bool** edges, int n, int& startVertex, int& endVertex) {
    bool* visited {new bool[n]()};
    for (int i{}; i<n; i++) visited[i] = false;

    std::queue<int> pendingVertex;
    std::map<int,int> path;
    pendingVertex.push(startVertex);
    visited[startVertex] = true;

    while(!pendingVertex.empty()){
        int currentVertex = pendingVertex.front();

        if (currentVertex == endVertex) {
            break;
        }

        for(int i = 0; i<n; i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] && !visited[i]){
                path[i] = currentVertex;
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
        pendingVertex.pop();
        if (pendingVertex.empty()) return;
    }

    int i {endVertex};
    std::cout << i << " ";
    while(i != startVertex) {
        std::cout << path[i]  << " ";
        i = path[i];
    }

    delete visited;
}


int main(){
    int n, e;
    std::cin >> n >> e;

    bool** edges {new bool*[n]};
    for (int i{}; i<n; i++) {
        edges[i] = new bool[n];
        for (int j{}; j<n; j++) {
            edges[i][j] = false;
        }
    }

    for (int i{}; i<e; i++) {
        int sv, ev;
        std::cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }

    int startVertex, endVertex;
    std::cin >> startVertex >> endVertex;

    BFS(edges,n,startVertex,endVertex);

    for (int i{}; i<n; i++) {
        delete [] edges[i];
    }

    delete [] edges;
}