#include<bits/stdc++.h>
using namespace std;

int search(int* arr, int start, int end, int x){
    if(start>end){
        return -1;
    }
    if(arr[start] == x){
        return start;
    }
    return search(arr,start+1,end,x); 
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
    cout << search(arr,0,n-1,x) << endl;
}