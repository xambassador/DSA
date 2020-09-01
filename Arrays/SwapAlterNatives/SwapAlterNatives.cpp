#include<bits/stdc++.h>
using namespace std;

void swapAlternative(int* arr, int size){
    int i{};
    int j{1};
    while(j<size){
        int tmp{arr[i]};
        arr[i] = arr[j];
        arr[j] = tmp;
        i+=2;
        j+=2;
    }
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{}; i<n; i++){
        cin >> arr[i];
    }
    swapAlternative(arr,n);
    for(int i{};i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
}