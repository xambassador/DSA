#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void wave(int** arr, int n, int m) {
    for(int col{}; col < m; col++) {
        if(col % 2 == 0) {
            for(int row{}; row < n; row++) cout << arr[row][col] << " ";
        } else {
            for(int row{n - 1}; row >= 0; row--) cout << arr[row][col] << " ";
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int** arr{new int*[n]};
    for(int i{};i < n; i++) {
        arr[i] = new int[m];
        for(int j{}; j < m; j++) cin >> arr[i][j];
    }
    wave(arr,n,m);

    for(int i{}; i < n; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}
