#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
    if (node == graph.size() - 1) {
        result.push_back(path);
        return;
    }
    for (auto& next : graph[node]) {
        path.push_back(next);
        dfs(graph, next, path, result);
        path.pop_back();
    }
}

// -----------------------------------------------------------------------------
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    path.push_back(0);
    dfs(graph, 0, path, result);
    return result;
}

// -----------------------------------------------------------------------------
int main() {
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> result {allPathsSourceTarget(graph)};
    for (auto& path : result) {
        for (auto& node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
