#include<bits/stdc++.h>
using namespace std;

void spiral(int** arr, int n, int m){
    int total{n*m};
    int start_row{};
    int start_col{};
    int end_row{n-1};
    int end_col{m-1};
    int cnt{};
    while(cnt < total){
        for(int col{start_col};col<=end_col;col++){
            cout << arr[start_row][col] << " ";
            cnt++;
            if(cnt > total){
                break;
            }
        }
        start_row++;
        for(int row{start_row};row<=end_row;row++){
            cout << arr[row][end_col] << " ";
            cnt++;
            if(cnt > total){
                break;
            }
        }
        end_col--;
        for(int col{end_col};col>=start_col;col--){
            cout << arr[end_row][col] << " ";
            cnt++;
            if(cnt > total){
                break;
            }
        }
        end_row--;
        for(int row{end_row};row>=start_row;row--){
            cout << arr[row][start_col] << " ";
            cnt++;
            if(cnt > total){
                break;
            }
        }
        start_col++;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int** arr{new int*[n]};
    for(int i{};i<n;i++){
        arr[i] = new int[m];
        for(int j{};j<m;j++){
            cin >> arr[i][j];
        }
    }
    spiral(arr,n,m);   
}