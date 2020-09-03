#include<bits/stdc++.h>
using namespace std;

int search(int* arr, int start, int end, int x){
    if(start > end) return -1;
    int mid{(start+end)/2};
    if(arr[mid]==x){
        return mid;
    }else if(x<arr[mid]){
        return search(arr,start,mid-1,x);
    }else {
        return search(arr,mid+1,end,x);
    }
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