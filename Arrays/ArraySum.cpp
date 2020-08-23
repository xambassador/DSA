#include<bits/stdc++.h>
using namespace std;


int sum(int* arr, int size){
    int ans{};
    for(int i{};i<size;i++){
        ans += arr[i];
    }
    return ans;
}

int main(){
    int size;
    cin >> size;
    int* arr{new int[size]};
    for(int i{}; i<size; i++){
        cin >> arr[i];
    }
    cout << sum(arr,size) << endl;
}