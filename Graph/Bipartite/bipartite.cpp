#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;


bool bipartite(vector<int>* graph) {
    unordered_set<int> sets[2];
    queue<int> pendingNodes;

    pendingNodes.push(0);
    sets[0].insert(0);

    while(!pendingNodes.empty()) {
        int currentVertex {pendingNodes.front()};
        pendingNodes.pop();
        // Find the set in which current vertex is exists
        int currentSet {(sets[0].count(currentVertex) > 0 ? 0 : 1)};

        // Explore neighbours and check if any neighbour is exists in same set where current vertex is.
        for (int i{}; i<graph[currentVertex].size(); i++) {
            int currentNeighbour {graph[currentVertex][i]};

            // If current neighbour is not in any set
            if (sets[0].count(currentNeighbour) == 0 && sets[1].count(currentNeighbour) == 0) {
                sets[1 - currentSet].insert(currentNeighbour);
                pendingNodes.push(currentNeighbour);
            }

            // If current neighbour found in set where current vertex is
            else if (sets[currentSet].count(currentNeighbour) > 0) return false;
        }

    }

    return true;
}


int main() {
    while (true) {
        int numberOfvertices;
        cin >> numberOfvertices;

        if (numberOfvertices == 0) return 0;
        
        int numberOfEdges;
        cin >> numberOfEdges;


        vector<int>* graph {new vector<int>[numberOfEdges]};
        for (int i{}; i<numberOfEdges; i++) {
            int startVertex, endVertex;
            cin >> startVertex >> endVertex;
            graph[startVertex].push_back(endVertex);
            graph[endVertex].push_back(startVertex);
        }

        bool isBipartriteGraph {bipartite(graph)};

        if (isBipartriteGraph) {
            cout << "Graph is Colorable" << endl;
        } else {
            cout << "NOT BIPARTRITE" << endl;
        }

        delete [] graph;
    }
}