#include <iostream>
#include <vector>


std::vector<int>* getPath(bool** edges, int n, bool* visited, int& startVertex, int& endVertex) {
    // startVertex and endVertex is same
    if (startVertex == endVertex) {
        std::vector<int>* ans {new std::vector<int>()};
        ans->push_back(startVertex);
        return ans;
    }

    visited[startVertex] = true;

    for (int i{}; i<n; i++) {
        if (edges[startVertex][i] && !visited[i]) {
            std::vector<int>* ans {getPath(edges, n, visited, i, endVertex)};
            if (ans) {
                ans->push_back(startVertex);
                return ans;
            } else {
                continue;
            }
        }
    }

    return NULL;
}

int main() {
    int n,e;
    std::cin >> n >> e;
    
    bool** edges {new bool*[n]};
    for (int i{}; i<n; i++) {
        edges[i] = new bool[n];
        for (int j{}; j<n; j++) {
            edges[i][j] = false;
        }
    }

    bool* visited {new bool[n]};
    for (int i{}; i<n; i++) visited[i] = false;

    for (int i{}; i<e; i++) {
        int sv, ev;
        std::cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }

    int startVertex, endVertex;
    std::cin >> startVertex >> endVertex;

    std::vector<int>* ans {getPath(edges, n, visited, startVertex, endVertex)};
    if (ans) {
        for (int i{}; i<ans->size(); i++) {
            std::cout << ans->at(i) << " ";
        }
        std::cout << std::endl;
    }

    for (int i{}; i<n; i++) {
        delete [] edges[i];
    }

    delete [] edges;
    delete [] visited;
    delete ans;
}
