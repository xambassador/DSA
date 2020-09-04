#include<bits/stdc++.h>
using namespace std;
 
bool checkNumber(int* arr, int n, int x){
    //1. Base case, if array is empty there is no element, so x is not there in array
    if(n == 0){
        return false;
    }
    //2. Check our element whether it is equal to x or not
    // If it is equal to x then just return true other wise we give rest work to recursion
    if(arr[0] == x){
        return true;
    } 
    return checkNumber(arr+1,n-1,x);
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
    cout << boolalpha << checkNumber(arr,n,x) << endl;
}