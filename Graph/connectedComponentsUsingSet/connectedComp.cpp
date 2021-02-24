#include<iostream>
#include<vector>
#include<unordered_set>

void dfs(std::vector<int>* edges, int start, std::unordered_set<int>* component, bool* visited) {
    visited[start] = true;
    component->insert(start);
    for (int i{}; i<edges[start].size(); i++) {
        int nextVertex {edges[start][i]};
        if (!visited[nextVertex]){
            dfs(edges, nextVertex, component, visited);
        }
    }
}

std::unordered_set<std::unordered_set<int>* >* getComponents(std::vector<int>* edges, int n) {
    bool* visited {new bool[n]};
    for (int i{}; i<n; i++) visited[i] = false;

    std::unordered_set<std::unordered_set<int>* >* output {new std::unordered_set<std::unordered_set<int>* >()};
    for (int i{}; i<n; i++) {
        if (!visited[i]) {
            std::unordered_set<int>* component {new std::unordered_set<int>()};
            dfs(edges, i, component, visited);
            output->insert(component);
            delete component;
        }
    }
    delete [] visited;
    return output;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int>* edges {new std::vector<int>[n]};
    int m;
    std::cin >> m;
    for (int i{}; i<m ; i++) {
        int sv, ev;
        std::cin >> sv >> ev;
        edges[sv - 1].push_back(ev-1);
        edges[ev - 1].push_back(sv-1);
    } 

    std::unordered_set<std::unordered_set<int>* >* components {getComponents(edges, n)};
    std::unordered_set<std::unordered_set<int>* >::iterator it1 {components->begin()};
    while(it1 != components->end()) {
        std::unordered_set<int>* component {*it1};
        std::unordered_set<int>::iterator it2 {component->begin()};
        while(it2 != component->end()) {
            std::cout << *it2 + 1 << " ";
            it2++;
        }std::cout << std::endl;
        delete component;
        it1++;
    }    

    delete components;
}   