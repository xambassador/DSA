#include<bits/stdc++.h>
using namespace std;
 
int subsetSum(int* arr, int n, int output[][100], int k){
    if(n == 0){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }else{
            return 0;
        }
    }
    int toutput1[100][100],toutput2[100][100];
    int size1{subsetSum(arr+1,n-1,toutput1,k)};
    int size2{subsetSum(arr+1,n-1,toutput2,k-arr[0])};
    int startingRowIndex{0};
    for(int i{};i<size1;i++){
        for(int j{};j<=toutput1[i][0];j++){
            output[startingRowIndex][j] = toutput1[i][j];
        }
        startingRowIndex++;
    }
    for(int i{};i<size2;i++){
        output[startingRowIndex][0] = toutput2[i][0]+1;
        output[startingRowIndex][1] = arr[0];
        for(int j{1};j<=output[i][0];j++){
            output[startingRowIndex][j+1] = toutput2[i][j];
        }
        startingRowIndex++;
    }
    return size1+size2;
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int output[100][100];
    int ans{subsetSum(arr,n,output,k)};
    for(int i{};i<ans;i++){
        for(int j{1};j<=output[i][0];j++){
            cout << output[i][j] << " ";
        }cout << endl;
    }
    delete arr;
}