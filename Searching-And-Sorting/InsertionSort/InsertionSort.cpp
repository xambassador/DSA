#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int* arr, int n){
    for(int i{1};i<n;i++){
        int pickElement{arr[i]};
        int j;
        for(j=i-1;j>=0&&arr[j]>pickElement;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = pickElement;
    }
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    InsertionSort(arr,n);
    for(int i{};i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
    delete arr;
}