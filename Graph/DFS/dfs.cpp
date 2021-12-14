#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// print using DFS
void print(int** edges, int n, int startingVertex, bool* visited) {
    cout << startingVertex << endl;
    // Mark current vertex as visited
    visited[startingVertex] = true;

    for(int i{}; i < n; i++) {
        // Check for edges between current vertex and adjecent vertex
        if (edges[startingVertex][i] == 1) {
            // Check if that vertex is already visited or not
            if (visited[i]) continue;
            if (i == startingVertex) continue;
            print(edges, n, i, visited);
        }
    }
}

int main() {
    int n; // vertex
    int e; // edges
    cin >> n >> e;
    // Adjancy matrix
    int** edges {new int*[n]};
    for (int i{}; i < n; i++) {
        edges[i] = new int[n];
        for (int j{}; j < n; j++) edges[i][j] = 0;
    }

    // Take input
    for (int i{}; i < e; i++) {
        int startVertex, endVertex;
        cin >> startVertex >> endVertex;
        edges[startVertex][endVertex] = 1;
        edges[endVertex][startVertex] = 1;
    }

    // Array for mark all visited nodes
    bool* visited{new bool[n]()};
    print(edges, n, 0, visited);

    // Free memory
    for(int i{}; i < n; i++) delete edges[i];
    delete [] edges;
    delete [] visited;
}
