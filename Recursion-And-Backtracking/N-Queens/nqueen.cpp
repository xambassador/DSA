#include<iostream>
using namespace std;

bool board[21][21];

bool isPossible(int n, int row, int col) {
    for(int i{row-1}; i>=0; i--) {
        if(board[i][col]) return false;
    }

    for(int i{row-1}, j{col-1}; i>=0 && j >=0; i--,j--) {
        if(board[i][j]) return false;
    }

    for(int i{row-1}, j{col+1}; i>=0 && j<n; i--,j++) {
        if(board[i][j]) return false;
    }
    return true;
}


void nQueenHelper(int n, int row) {
    if(row >= n) {
        for(int i{}; i<n; i++) {
            for(int j{}; j<n; j++) {
                cout << board[i][j] << ' ';
            }
        }cout << endl;
        return;
    }

    for(int i{}; i<n; i++) {
        if(isPossible(n,row,i)) {
            board[row][i] = 1;
            nQueenHelper(n,row+1);
            board[row][i] = 0;
        }
    }
}


void placeNQueens(int n) {
    for(int i{}; i<n; i++) {
        for(int j{}; j<n; j++) {
            board[i][j] = 0;
        }
    }
    nQueenHelper(n, 0);
}


int main() {
    int n;
    cin >> n;
    placeNQueens(n);
}