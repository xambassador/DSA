#include<iostream>
#include<algorithm>
#include<vector>

class Edge {
    public:
    int sv;
    int ev;
    int weight;
};


bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}


int getParent(int v, int* parent) {
    if (v == parent[v]) return v;
    return getParent(parent[v],parent);
}

void kruskal(Edge* edges, int V, int E) {
    std::vector<Edge> output;
    int parent[V];
    for (int i{}; i<V; i++) parent[i] = i;
    int i{};
    int cnt{};
    while(cnt < (V-1)) {
        int p1 {getParent(edges[i].sv,parent)};
        int p2 {getParent(edges[i].ev,parent)};

        if (p1 != p2) {
            output.push_back(edges[i]);
            cnt++;
            parent[p1] = p2;
        }
        i++;
    }

    for (auto i : output) {
        if (i.sv < i.ev) std::cout << i.sv << " " << i.ev << " " << i.weight << std::endl;
        else std::cout << i.ev << " " << i.sv << " " << i.weight << std::endl;
    }
}


int main(){
    int V,E;
    std::cin >> V >> E;

    Edge* edges {new Edge[E]};
    for (int i{}; i<E; i++) {
        std::cin >> edges[i].sv >> edges[i].ev >> edges[i].weight;
    }

    std::sort(edges,edges + E, compare);
    kruskal(edges,V,E);
}
