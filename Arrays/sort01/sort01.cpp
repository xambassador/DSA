#include<bits/stdc++.h>
using namespace std;


void sort01(int* arr, int n){
    int i{};
    int j{n-1};
    while(i < j){
        if(arr[i] == 0 && arr[j] == 1){
            i++;
            j--;
        }else if(arr[i] == 0 && arr[j] == 0){
            i++;
        }else if(arr[i] == 1 && arr[j] == 0){
            int tmp{arr[i]};
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }else if(arr[i] == 1 && arr[j] == 1){
            j--;
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
    sort01(arr,n);
    for(int i{};i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
}