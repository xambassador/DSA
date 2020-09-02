#include<bits/stdc++.h>
using namespace std;

void printColSum(int arr[][100], int n, int m){
    for(int col{};col<m;col++){
        int sum{};
        for(int row{};row<n;row++){
            sum += arr[row][col];
        }
        cout << sum << " ";
    }cout << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    int arr[100][100];
    for(int row{};row<n;row++){
        for(int col{};col<m;col++){
            cin >> arr[row][col];
        }
    }
    printColSum(arr,n,m);
}