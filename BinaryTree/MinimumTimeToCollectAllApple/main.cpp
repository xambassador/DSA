#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& hasApple, int currentNode) {
    // Mark current node as visited.
    visited[currentNode] = true;
    int time {};
    // Go through each vertex adjacent to current node.
    for (int next : graph[currentNode]) {
        // If the vertex is already visited, skip it.
        if (visited[next]) continue;
        // Recursively call dfs on the next vertex.
        int subTime {dfs(graph, visited, hasApple, next)};
        // If the next vertex has an apple or the subTime is greater than 0,
        // add 2 to the time. Because if next node has an apple then we need
        // to go that node which take 1 second and we need to come back to
        // current node which take 1 second.
        if (subTime > 0 || hasApple[next]) time += subTime + 2;
    }
    return time;
}

// -----------------------------------------------------------------------------
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    return dfs(graph, visited, hasApple, 0);
}

// -----------------------------------------------------------------------------
int main () {
    int n {7};
    vector<vector<int>> edges {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple {false,false,true,false,true,true,false};
    cout << minTime(n, edges, hasApple) << endl;
    return 0;
}
