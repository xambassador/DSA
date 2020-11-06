#include<iostream>
#include<cstring>
using namespace std;


int ans[11][11];


void print(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << " ";
        }
    }cout << endl;
}

void help(int maze[][11], int n, int row, int col) {
    if(row == n-1 && col == n-1) {
        ans[row][col] = 1;
        print(n);
        ans[row][col] = 0;
        return;
    }

    if(maze[row][col] == 0) return;

    ans[row][col] = 1;
    if(col+1<n && ans[row][col+1] != 1 && maze[row][col] != 0) {
        help(maze,n,row,col+1);
        ans[row][col+1] = 0;   
    }

    if(col-1>=0 && ans[row][col-1] != 1 && maze[row][col-1] != 0) {
        help(maze,n,row,col-1);
        ans[row][col-1] = 0;   
    }

    if(row+1<n && ans[row+1][col] != 1 && maze[row+1][col] != 0) {
        help(maze,n,row+1,col);
        ans[row+1][col] = 0;   
    }

    if(row-1>=0 && ans[row-1][col] != 1 && maze[row-1][col] != 0) {
        help(maze,n,row-1,col);
        ans[row][col+1] = 0;   
    }

    ans[row][col] = 0;
}


void rateInMaze(int maze[][11], int n) {
    memset(ans, 0, 11*11*sizeof(int));
    help(maze, n, 0,0);
}


int main() {
    int n;
    cin >> n;
    int maze[11][11];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    rateInMaze(maze,n); 
}   