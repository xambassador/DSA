#include<iostream>
#include<vector>
using namespace std;
 


void resetHorizontal(char grid[10][10], int row, int col, vector<bool>& v) {
    int j{col};

    for(int i{}; i<v.size(); i++) {
        if(v[i]) {
            grid[row][j] = '-';
        }
        j++;
    }
}

void resetVertical(char grid[10][10], int row, int col, vector<bool>& v) {
    int j{row};

    for(int i{}; i<v.size(); i++) {
        if(v[i]) {
            grid[j][col] = '-';
        }
        j++;
    }
}


void setHorizontal(char grid[10][10], int row, int col, string s, vector<bool>& v) {
    int j{col};
    for(int i{}; i<s.length(); i++) {
        if(grid[row][j] == '-') {
            v.push_back(true);
            grid[row][j] = s[i];
        }else {
            v.push_back(false);
        }
        j++;
    }
} 

void setVerticle(char grid[10][10], int row, int col, string s, vector<bool>& v) {
    int j{row};
    for(int i{}; i<s.length(); i++) {
        if(grid[j][col] == '-') {
            v.push_back(true);
            grid[j][col] = s[i];
        }else {
            v.push_back(false);
        }
        j++;
    }    
} 


bool isVerticleAllow(char grid[10][10], int row, int col, string s) {
    int j{row};
    for(int i{}; i<s.length(); i++) {
        if(j > 9) {
            return false;
        }

        if(grid[j][col] == '+' || (grid[j][col] != '-' && grid[j][col] != s[i])) {
            return false;
        }

        if(grid[j][col] == '-' || grid[j][col] == s[i]) {
            j++;
        }
    }
    return true;
}

bool isHorizontalAllow(char grid[10][10], int row, int col, string s) {
    int j{col};
    for(int i{}; i<s.length(); i++) {
        if(j > 9) {
            return false;
        }

        if(grid[row][j] == '+' || (grid[row][j] != '-' && grid[row][j] != s[i])) {
            return false;
        }

        if(grid[row][j] == '-' || grid[row][j] == s[i]) {
            j++;
        }
    }
    return true;
}
 
bool solve(char grid[10][10], int index, vector<string> words) {

    if(index >= words.size()) {
        return true;
    }

    for(int i{}; i<10;i++) {
        for(int j{}; j<10; j++) {
            if(grid[i][j] == '-' || grid[i][j] == words[index][0]) {
                if(isVerticleAllow(grid,i,j,words[index])) {
                    vector<bool> v;
                    setVerticle(grid,i,j,words[index],v);
                    if(solve(grid,index+1,words)) {
                        return true;
                    }
                    resetVertical(grid,i,j,v);
                }

                if(isHorizontalAllow(grid,i,j,words[index])) {
                    vector<bool> v;
                    setHorizontal(grid,i,j,words[index],v);
                    if(solve(grid,index+1,words)) {
                        return true;
                    }
                    resetHorizontal(grid,i,j,v);
                }
            }
        }
    }  
}


int main() {
    char grid[10][10];
    for(int i{}; i<10; i++) {
        for(int j{}; j<10; j++) {
            cin >> grid[i][j];
        }
    }

    string s;
    cin >> s;
    
    vector<string> words;

    for(int i{}; i<s.length(); i++) {
        int j{i};
        while(s[j] != ';' && j<s.length()) {
            j++;
        }
        words.push_back(s.substr(i,j-i));
        i = j;
        j++;
    }


    bool ans {solve(grid,0, words)};
    cout << boolalpha << ans << endl;
    if(ans) {
        for(int i{}; i<10; i++) {
            for(int j{}; j<10; j++) {
                cout << grid[i][j] << ' ';
            }cout << endl;
        }
    }
}