#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;


int dfs(const vector<vector<int>>& graph, int u, int prev, int seats, long long& ans) {
    int people {1};
    for (const int v : graph[u]) {
        if (v == prev)
        continue;
        people += dfs(graph, v, u, seats, ans);
    }
    if (u > 0) ans += (people + seats - 1) / seats;
    return people;
}

long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    long long ans{};
    vector<vector<int>> graph(roads.size() + 1);
    for (const vector<int>& road : roads) {
      const int u {road[0]};
      const int v {road[1]};
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, -1, seats, ans);
    return ans;
}
