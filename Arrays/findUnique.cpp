#include<bits/stdc++.h>
using namespace std;

int uniqueElement(int* arr, int size){
    sort(arr,arr+size);
    int i{},ans{};
    while(i<size){
        if(arr[i] != arr[i+1]){
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
    for(int i{}; i<n; i++){
        cin >> arr[i];
    }
    cout << uniqueElement(arr,n) << endl;
}