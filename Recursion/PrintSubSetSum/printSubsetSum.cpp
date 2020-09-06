#include<bits/stdc++.h>
using namespace std;
 
void printSubsetSum(int* arr, int n, int* output, int k, int nextIndex){
    if(n == 0){
        if(k == 0){
            for(int i{}; i<nextIndex;i++){
                cout << output[i] << " ";
            }cout << endl;
        }
        return;
    }
    printSubsetSum(arr+1,n-1,output,k,nextIndex);
    int narr[nextIndex+1];
    narr[0] = arr[0];
    for(int i{};i<nextIndex;i++){
        narr[i+1] = output[i];
    }
    printSubsetSum(arr+1,n-1,narr,k-arr[0],nextIndex+1);
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
    int* output{new int[n]};
    printSubsetSum(arr,n,output,k,0);
    delete arr;
    delete output;
}