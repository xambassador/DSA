#include <vector>
#include <utility>
#include <climits>
#include <queue>
#include <algorithm>
using std::min;
using std::queue;
using std::vector;
using std::pair;

// -----------------------------------------------------------------------------------------
int minScore(int n, vector<vector<int>>& roads) {
    int ans {INT_MAX};
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto& road : roads) {
        graph[road[0]].push_back({road[1], road[2]});
        graph[road[1]].push_back({road[0], road[2]});
    }

    vector<int> visited(n + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int node {q.front()};
        q.pop();
        for (auto& [vertex, distance]: graph[node]) {
            ans = min(ans, distance);
            if (visited[vertex] == 0) {
                visited[vertex] = 1;
                q.push(vertex);
            }
        }
    }

    return ans;
}
