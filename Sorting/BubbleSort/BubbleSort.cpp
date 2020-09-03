#include<bits/stdc++.h>
using namespace std;


void BubbleSort(int* arr, int n){
    for(int i{};i<n-1;i++){
        for(int j{};j<n-1;j++){
            if(arr[j] > arr[j+1]){
                int t{arr[j]};
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    BubbleSort(arr,n);
    for(int i{};i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
    delete arr;
}