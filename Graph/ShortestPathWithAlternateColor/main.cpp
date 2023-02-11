#include <iostream>
#include <vector>
#include <queue>
using std::queue;
using std::vector;
using std::pair;
using std::min;
using std::cin;
using std::cout;
using std::endl;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    // 0: red, 1: blue
    // create graph
    vector<vector<pair<int, int>>> graph(n);
    // Add edges
    for (auto& edge : redEdges) graph[edge[0]].push_back({edge[1], 0});
    for (auto& edge : blueEdges) graph[edge[0]].push_back({edge[1], 1});
    vector<vector<int>> distance(n, vector<int>(2, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({0, 1});
    distance[0][0] = 0;
    distance[0][1] = 0;
    while (!q.empty()) {
        auto node = q.front().first;
        auto color = q.front().second;
        q.pop();
        for (auto& g : graph[node]) {
            auto next = g.first;
            auto nextColor = g.second;
            if (nextColor == color) {
                continue;
            }
            if (distance[next][nextColor] != -1) {
                continue;
            }
            distance[next][nextColor] = distance[node][color] + 1;
            q.push({next, nextColor});
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (distance[i][0] == -1) {
            ans[i] = distance[i][1];
        } else if (distance[i][1] == -1) {
            ans[i] = distance[i][0];
        } else {
            ans[i] = min(distance[i][0], distance[i][1]);
        }
    }
    return ans;
}
