#include<iostream>
#include<vector>
#include<algorithm>



void DFS(bool** edges, int n, bool* visited, int sv,std::vector<int>& arr) {
    visited[sv] = true;
    arr.push_back(sv);
    for (int i{}; i<n; i++) {
        if (i == sv) continue;

        if (edges[sv][i] && !visited[i]) {
            DFS(edges,n,visited,i,arr);
        }
    }
}


std::vector<std::vector<int> >* connectedComponents(bool** edges, int n){
    bool* visited {new bool[n]};
    for(int i{}; i<n; i++) visited[i] = false;
    
    std::vector<std::vector<int> >* ans {new std::vector<std::vector<int> >()};
    std::vector<int> tmp;
    for (int i{}; i<n; i++) {
        if(!visited[i]) {
            DFS(edges,n,visited,i,tmp);
            std::sort(tmp.begin(), tmp.end());
            ans->push_back(tmp);
            tmp.clear();
        }
    }

    delete [] visited;
    return ans;
    
}

int main(){
    int n,e;
    std::cin >> n >> e;

    bool** edges {new bool*[n]};
    for (int i{}; i<n; i++) {
        edges[i] = new bool[n];
        for (int j{}; j<n; j++) {
            edges[i][j] = false;
        }
    }

    for(int i{}; i<e; i++) {
        int sv,ev;
        std::cin >> sv >> ev;
        edges[sv][ev] = true;
        edges[ev][sv] = true;
    }


    std::vector<std::vector<int> >* ans {connectedComponents(edges,n)};
    
    for(int i{}; i<ans->size(); i++) {
        std::vector<int> arr {ans->at(i)};
        for(auto i : arr) {
            std::cout << i << " ";
        }std::cout << std::endl;
    }

    for(int i{}; i<n; i++) {
        delete [] edges[i];
    }


    delete [] edges;

    delete ans;
}