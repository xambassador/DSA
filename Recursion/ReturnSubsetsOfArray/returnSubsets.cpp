#include<bits/stdc++.h>
using namespace std;
 
int subsets(int* arr, int n, int output[][100]){
    if(n == 0){
        output[0][0] = 0;
        return 1;
    }
    int size{subsets(arr+1,n-1,output)};
    int startIndex{0};
    for(int i{};i<size;i++){
        output[i+size][0] = 1+output[i][0];
        output[i+size][1] = arr[0];
        for(int j{1};j<=output[i][0];j++){
            output[i+size][j+1] = output[i][j];
        }
    }
    return size*2;
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    int output[100][100];
    int ans{subsets(arr,n,output)};
    for(int i{};i<ans;i++){
        for(int j{1};j<=output[i][0];j++){
            cout << output[i][j] << " ";
        }cout << endl;
    }
    delete arr;
}