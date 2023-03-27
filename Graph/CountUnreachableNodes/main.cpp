#include <vector>
using std::vector;

void dfs(vector<int>adj[], int src, vector<bool>& visited, int& counter) {
    if (visited[src]) return;
    visited[src]=true;
    counter++;
    for(auto ele : adj[src]) {
        if (!visited[ele]) dfs(adj, ele, visited, counter);
    }
}

long long countPairs(int n, vector<vector<int>>& edges) {
    vector<int>adj[n];
    for(auto ele : edges) {
        adj[ele[0]].push_back(ele[1]);
        adj[ele[1]].push_back(ele[0]);
    }

    long long res {};
    vector<bool>vis(n, false);
    vector<int>temp;

    for(int i{}; i < n; i++) {
        if(!vis[i]) {
            int counter {};
            dfs(adj, i, vis, counter);
            temp.push_back(counter);
        }
    }

    int total {};
    for(int i{}; i < temp.size(); i++){
        res += (long)((long)temp[i]*(long)(n - total - temp[i]));
        total += temp[i];
    }

    return res;
}
