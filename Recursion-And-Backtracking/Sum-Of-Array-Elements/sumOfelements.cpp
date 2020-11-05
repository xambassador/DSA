#include<bits/stdc++.h>
using namespace std;
 
int sum(int* arr, int n){
    //1. Base case : If array is empty, there is no elements so sum is zero
    if(n == 0){
        return 0;
    }
    //2. Call recursion for say give me your answer and i add my element to your answer and return final answer
    return sum(arr+1,n-1) + arr[0];
    
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    cout << sum(arr,n) << endl;
    delete arr;
}