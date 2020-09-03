#include<bits/stdc++.h>
using namespace std;

void pushZeroToEnd(int* arr, int n){
    int i{};
    int j{1};
    while(j<n){
        if(arr[i] == 0){
            if(arr[j] == 0){
                j++;
            }else{
                int t{arr[i]};
                arr[i] = arr[j];
                arr[j] = t;
            }
        }else{
            i++;
            j++;
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
    pushZeroToEnd(arr,n);
    for(int i{};i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
}