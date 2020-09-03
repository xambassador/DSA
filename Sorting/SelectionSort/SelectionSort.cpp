#include<bits/stdc++.h>
using namespace std;

void SelSort(int* arr, int n){
    for(int i{};i<n;i++){
        int min{arr[i]};
        int minIndex{i};
        for(int j{i+1};j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minIndex = j;
            }
        }
        int t{arr[i]};
        arr[i] = arr[minIndex];
        arr[minIndex] = t;
    }
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    SelSort(arr,n);
    for(int i{};i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
    delete arr;
}