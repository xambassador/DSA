#include<bits/stdc++.h>
using namespace std;
 
int firstIndexHelp(int* arr, int start, int end, int x){
    //1. Base case, if array is empty, then x is not there
    if(start > end){
        return -1;
    }
    //2. Because we need to find first index of x element, first we do our calculation.
    //we take decision on start index
    if(arr[start] == x){
        return start;
    }
    //3. If our element is not equal to x then either it is present in rest of array or may be not
    //So now give this work to recursion and return it's answer directly beacuse we already take out decision.
    return firstIndexHelp(arr,start+1,end,x);
}

int firstIndex(int* arr, int n, int x){
    return firstIndexHelp(arr,0,n-1,x);
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
    cout << firstIndex(arr,n,x) << endl;
}