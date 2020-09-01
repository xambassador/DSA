#include<bits/stdc++.h>
using namespace std;

int findDuplicate(int* arr, int n){
    sort(arr,arr+n);
    int i{};
    int ans{};
    while(i<n){
        if(arr[i] == arr[i+1]){
            ans = arr[i];
            break;
        }
        i++;
    }
    return ans;
}


int main(){ 
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    cout << findDuplicate(arr,n) << endl;
}