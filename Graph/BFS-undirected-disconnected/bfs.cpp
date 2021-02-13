#include<iostream>
#include<queue>

// BFS traversal

void print(bool** edges, int n, int sv, bool* visited) {
    std::queue<int> pendingVertex;
    pendingVertex.push(sv);
    visited[sv] = true;
    while(!pendingVertex.empty()){
        int currentVertex = pendingVertex.front();
        pendingVertex.pop();
        std::cout << currentVertex << " ";
        for(int i = 0; i<n; i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertex.push(i);
                visited[i] = true;
            }
        }
    }
}


void printBFS(bool** edges, int n) {
    bool* visited {new bool[n]};
    for (int i{}; i<n; i++) visited[i] = false;
    for (int i{}; i<n; i++) {
        if (!visited[i]) {
            print(edges,n,i,visited);
        }
    }

    delete [] visited;
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

    printBFS(edges,n);

    for (int i{}; i<n; i++) {
        delete [] edges[i];
    }

    delete [] edges;
}