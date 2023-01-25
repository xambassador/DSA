#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using std::max;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

 void dfs (int node, vector<int>& edges, vector<int>& distance, vector<bool>& visited) {
    // Mark the current node as visited
    visited[node] = true;
    // Get neighbour of the current node
    int neighbor {(int)edges[node]};
    // If the neighbour is not visited then call dfs on it
    if (neighbor != -1 && visited[neighbor] == false) {
        distance[neighbor] = distance[node] + 1;
        dfs(neighbor, edges, distance, visited);
    }
}

// Leetcode 2359. Find Closest Node to Given Two Nodes
int closestMeetingNode (vector<int>& edges, int node1, int node2) {
    int n {(int)edges.size()};
    int ans {-1};
    int minDist {INT_MAX};
    //dist1 store the distance from node1 to all the neighbour nodes and dist2 store the distance from node2 to all the neighbour nodes
    vector<int> dist1(n, 0), dist2(n, 0);
    //visited array helps us to identify wheather we visited to particular node form node1 or not similarly for visited2
    vector<bool> visited1(n, false), visited2(n, false);
    //calling dfs from both the nodes i.e. node1 and node2
    dfs(node1, edges, dist1, visited1);
    dfs(node2, edges, dist2, visited2);

    for (int currNode{}; currNode < n; currNode++) {
        if (visited1[currNode] == true && visited2[currNode] == true && minDist > max(dist1[currNode], dist2[currNode])) {
            minDist = max(dist1[currNode], dist2[currNode]);
            ans = currNode;
        }
    }
    return ans;
}

// -----------------------------------------------------------------------------------------
int main () {
    int n;
    cin >> n;
    vector<int> edges(n);
    for (int i = 0; i < n; i++) cin >> edges[i];
    int node1, node2;
    cin >> node1 >> node2;
    cout << closestMeetingNode(edges, node1, node2) << endl;
    return 0;
}
