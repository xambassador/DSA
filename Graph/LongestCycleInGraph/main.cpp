#include <vector>
#include <algorithm>
using std::max;
using std::vector;

// -----------------------------------------------------------------------------------------
int longestCycle(vector<int>& edges) {
    int ans {-1}, time {1};
    vector<int> timeVisited(edges.size(), 0);
    for (int i{}; i < edges.size(); ++i) {
        if (timeVisited[i] > 0) continue;
        int startTime {time};
        int u {i};
        while (u != -1 && timeVisited[u] == 0) {
            timeVisited[u] = time++;
            u = edges[u]; // Move to next node
        }
        if (u != -1 && timeVisited[u] >= startTime) ans = max(ans, time - timeVisited[u]);
    }
    return ans;
}
