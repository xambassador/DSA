#include<iostream>
#include<vector>
#include<unordered_set>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

void dfs(std::vector<int>* edges, int start, unordered_set<int>* component, bool* visited) {
    visited[start] = true;
    component->insert(start);
    for (int i{}; i < edges[start].size(); i++) {
        int nextVertex{edges[start][i]};
        if (!visited[nextVertex]) dfs(edges, nextVertex, component, visited);
    }
}

unordered_set<unordered_set<int>* >* getComponents(vector<int>* edges, int n) {
    bool* visited{new bool[n]};
    for (int i{}; i < n; i++) visited[i] = false;
    unordered_set<unordered_set<int>* >* output {new unordered_set<unordered_set<int>* >()};
    for (int i{}; i < n; i++) {
        if (!visited[i]) {
            unordered_set<int>* component{new unordered_set<int>()};
            dfs(edges, i, component, visited);
            output->insert(component);
            delete component;
        }
    }
    delete [] visited;
    return output;
}

int main(){
    int n, m;
    cin >> n;
    vector<int>* edges {new vector<int>[n]};
    cin >> m;
    for (int i{}; i < m ; i++) {
        int sv, ev;
        cin >> sv >> ev;
        edges[sv - 1].push_back(ev - 1);
        edges[ev - 1].push_back(sv - 1);
    }

    unordered_set<unordered_set<int>* >* components{getComponents(edges, n)};
    unordered_set<unordered_set<int>* >::iterator it1{components->begin()};
    while(it1 != components->end()) {
        unordered_set<int>* component{*it1};
        unordered_set<int>::iterator it2{component->begin()};
        while(it2 != component->end()) {
            cout << *it2 + 1 << " ";
            it2++;
        }
        cout << endl;
        delete component;
        it1++;
    }
    delete components;
}
