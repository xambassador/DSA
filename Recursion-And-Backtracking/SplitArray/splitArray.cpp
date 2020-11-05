#include<bits/stdc++.h>
using namespace std;
 
bool check(int* arr, int n, int start, int lsum, int rsum){
    if(start == n){
        return lsum == rsum;
    }
    if(arr[start]%5 == 0){
        lsum += arr[start];
    }else if(arr[start]%3 == 0){
        rsum += arr[start];
    }else{
        return check(arr,n,start+1, lsum+arr[start], rsum) || check(arr,n,start+1,lsum,rsum+arr[start]);
    }
    return check(arr,n,start+1,lsum,rsum);
}

bool splitArray(int* arr, int n){
    return check(arr,n,0,0,0);
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    cout << boolalpha << splitArray(arr,n) << endl;
    delete arr;
}