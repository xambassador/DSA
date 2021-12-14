#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>* getPath(bool** edges, int n, bool* visited, int& startVertex, int& endVertex) {
    // startVertex and endVertex is same
    if (startVertex == endVertex) {
        vector<int>* ans {new vector<int>()};
        ans->push_back(startVertex);
        return ans;
    }

    visited[startVertex] = true;

    for (int i{}; i < n; i++) {
        if (edges[startVertex][i] && !visited[i]) {
            vector<int>* ans {getPath(edges, n, visited, i, endVertex)};
            if (ans) {
                ans->push_back(startVertex);
                return ans;
            } else continue;
        }
    }
    return NULL;
}

int main() {
    int n, e;
    cin >> n >> e;

    bool** edges{new bool*[n]};
    for (int i{}; i < n; i++) {
        edges[i] = new bool[n];
        for (int j{}; j < n; j++) edges[i][j] = false;
    }

    bool* visited{new bool[n]};
    for (int i{}; i < n; i++) visited[i] = false;

    for (int i{}; i < e; i++) {
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }

    int startVertex, endVertex;
    cin >> startVertex >> endVertex;

    vector<int>* ans {getPath(edges, n, visited, startVertex, endVertex)};
    if (ans) {
        for (int i{}; i < ans->size(); i++) cout << ans->at(i) << " ";
        cout << std::endl;
    }

    for (int i{}; i < n; i++) delete [] edges[i];
    delete [] edges;
    delete [] visited;
    delete ans;
}
