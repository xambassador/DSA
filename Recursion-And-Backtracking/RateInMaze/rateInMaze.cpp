#include<iostream>
#include<cstring>
using namespace std;


int ans[20][20];


void print(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << ans[i][j] << " ";
        }
    }cout << endl;
}

void help(int maze[][20], int n, int row, int col) {
    if(row == n-1 && col == n-1) {
        ans[row][col] = 1;
        print(n);
        ans[row][col] = 0;
        return;
    }

    if(maze[row][col] == 0 || ans[row][col] == 1 || row < 0 || col < 0 || row >= n || col >= n) {
        return;
    }

    ans[row][col] = 1;
    help(maze,n,row-1,col);
    help(maze,n,row+1,col);
    help(maze,n,row,col+1);
    help(maze,n,row,col-1);
    ans[row][col] = 0;
    return;
}


void rateInMaze(int maze[][20], int n) {
    memset(ans, 0, 20*20*sizeof(int));
    help(maze, n, 0,0);
}


int main() {
    int n;
    cin >> n;
    int maze[20][20];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> maze[i][j];
        }
    }
    rateInMaze(maze,n); 
}   