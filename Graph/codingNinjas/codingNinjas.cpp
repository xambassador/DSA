#include<iostream>
#include<string>


bool searchWordDFS(char** grid, int row, int col, int i, int j, std::string word, int si) {
    int len {word.length()};
    if (si == len) return true;

    if (i < 0 || j < 0 || i >= row || j >= col) return false;

    if (grid[i][j] == word[si]) {
        char c {grid[i][j]};
        grid[i][j] = 'X'; // Mark as visited
        bool ans;
        if (searchWordDFS(grid,row,col,i-1,j,word,si+1)) {
            ans = true;
        } else if (searchWordDFS(grid,row,col,i+1,j,word,si+1)) {
            ans = true;
        } else if (searchWordDFS(grid,row,col,i,j-1,word,si+1)) {
            ans = true;
        } else if (searchWordDFS(grid,row,col,i,j+1,word,si+1)) {
            ans = true;
        } else if (searchWordDFS(grid,row,col,i+1,j+1,word,si+1)) {
            ans = true;
        } else if (searchWordDFS(grid,row,col,i+1,j-1,word,si+1)) {
            ans = true;
        } else if (searchWordDFS(grid,row,col,i-1,j+1,word,si+1)) {
            ans = true;
        } else if (searchWordDFS(grid,row,col,i-1,j-1,word,si+1)) {
            ans = true;
        } else {
            ans = false;
        }

        grid[i][j] = c; // mark as unvisited
        return ans;
    }
}

bool isPath(char** grid, int row, int col) {
    std::string word {"CODINGNINJA"};
    for (int i{}; i<row; i++){
        for (int j{};j<col;j++) {
            if (grid[i][j] == word[0]) {
                if (searchWordDFS(grid,row,col,i,j,word,0)) {
                    return true;
                }
            }
        }
    }

    return false;
}


int main() {
    int n,m;
    std::cin >> n >> m;

    char** grid {new char*[n]};
    for (int i{}; i<n; i++) {
        grid[i] = new char[m];
        for (int j{}; j<m; j++) {
            std::cin >> grid[i][j];
        }
    }

    bool ans {isPath(grid,n,m)};
    std::cout << ans << std::endl;

    for (int i{}; i<n; i++) {
        delete [] grid[i];
    }

    delete [] grid;
}