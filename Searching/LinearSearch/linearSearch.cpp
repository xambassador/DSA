#include<bits/stdc++.h>
using namespace std;

int search(int* arr, int n, int x){
    for(int i{};i<n;i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    int x;
    cin >> x;
    cout << search(arr,n,x) << endl;
}
