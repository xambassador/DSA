#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

void DFS(vector<int>* edges, int start, bool* visited, unordered_set<int>* component) {
    if (visited[start]) return;
    visited[start] = true;
    component->insert(start);
    for (vector<int>::iterator it {edges[start].begin()}; it!=edges[start].end(); it++) {
        if (!visited[*it]) {
            DFS(edges, *it, visited, component);
        }
    }
}


unordered_set<unordered_set<int>* >* getComponent(vector<int>* edges, int n) {
    bool* visited {new bool[n]};
    for (int i{}; i<n; i++) visited[i] = false;
    unordered_set<unordered_set<int>* >* output {new unordered_set<unordered_set<int>*>()};
    for (int i{}; i<n; i++) {
        if (!visited[i]) {
            unordered_set<int>* component {new unordered_set<int>()};
            DFS(edges, i, visited, component);
            output->insert(component);
        }
    }

    return output;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int* p{new int[n]};
        int* q{new int[n]};
        for (int i{}; i<n; i++) cin >> p[i];
        for (int i{}; i<n; i++) cin >> q[i];

        // create a graph
        // create adjancy list
        vector<int>* edges {new vector<int>[n]};
        for (int i{}; i<m; i++) {
            int a,b;
            cin >> a >> b;
            edges[a-1].push_back(b-1);
            edges[b-1].push_back(a-1);
        }

        unordered_set<unordered_set<int>* >* components {getComponent(edges, n)};
        unordered_set<unordered_set<int>* >::iterator it1 {components->begin()};
        bool canObtainPermutation = true;
        while(it1 != components->end()) {
            unordered_set<int>* component {*it1};
            unordered_set<int>::iterator it2 {component->begin()};
            unordered_set<int> pIndex;
            unordered_set<int> qIndex;

            while (it2 != component->end()) {
                pIndex.insert(p[*it2]);
                qIndex.insert(q[*it2]);
                it2++;
            }

            if (pIndex != qIndex) {
                canObtainPermutation = false;
            }

            it1++;

            delete component;
        }

        if (canObtainPermutation) cout << "YES" << endl;
        else cout << "NO" << endl;

        delete [] p;
        delete [] q;
        delete [] edges;
        delete components;
    }
}