#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

vector<int> dfs(int currentNode, int parentNode, vector<vector<int>>& graph, string& labels, vector<int>& ans) {
    vector<int> myNodeCounts(26);
    myNodeCounts[labels[currentNode] - 'a'] = 1;
    for (int& child : graph[currentNode]) {
        if (child != parentNode) {
            vector<int> childNodeCounts {dfs(child, currentNode, graph, labels, ans)};
            for (int i{}; i < 26; i++) myNodeCounts[i] += childNodeCounts[i];
        }
    }

    ans[currentNode] = myNodeCounts[labels[currentNode] - 'a'];
    return myNodeCounts;
}

// -----------------------------------------------------------------------------
vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<vector<int>> graph(n);
    for (auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<int> ans(n);
    dfs(0, -1, graph, labels, ans);
    return ans;
}

// -----------------------------------------------------------------------------
int main () {
    int n {7};
    vector<vector<int>> edges {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    string labels {"abaedcd"};
    vector<int> ans {countSubTrees(labels.length(), edges, labels)};
    for (int i{}; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
