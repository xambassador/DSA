#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

void DFS(bool** edges, int n, bool* visited, int sv,vector<int>& arr) {
    visited[sv] = true;
    arr.push_back(sv);
    for (int i{}; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] && !visited[i]) DFS(edges, n, visited, i, arr);
    }
}

vector<vector<int> >* connectedComponents(bool** edges, int n) {
    bool* visited{new bool[n]};
    for(int i{}; i < n; i++) visited[i] = false;
    vector<vector<int> >* ans {new vector<vector<int> >()};
    vector<int> tmp;
    for (int i{}; i < n; i++) {
        if(!visited[i]) {
            DFS(edges,n,visited,i,tmp);
            sort(tmp.begin(), tmp.end());
            ans->push_back(tmp);
            tmp.clear();
        }
    }
    delete [] visited;
    return ans;
}

int main() {
    int n, e;
    cin >> n >> e;

    bool** edges {new bool*[n]};
    for (int i{}; i < n; i++) {
        edges[i] = new bool[n];
        for (int j{}; j < n; j++) edges[i][j] = false;
    }

    for(int i{}; i < e; i++) {
        int sv, ev;
        cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }

    vector<vector<int> >* ans{connectedComponents(edges, n)};
    for(int i{}; i < ans->size(); i++) {
        vector<int> arr{ans->at(i)};
        for(auto i : arr) cout << i << " ";
        cout << std::endl;
    }

    for(int i{}; i < n; i++) delete [] edges[i];
    delete [] edges;
    delete ans;
}
