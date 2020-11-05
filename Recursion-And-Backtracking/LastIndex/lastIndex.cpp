#include<bits/stdc++.h>
using namespace std;
 
int lastIndexHelp(int* arr, int start, int end, int x){
    //1. Base case, if array is empty, then x is not there
    if(start>end){
        return -1;
    }
    //Here we need to return last index, so there is two options, one is there is only one 'x' element
    //Second is there is more than one 'x' element
    //2. First we call recursion and say find out last index of 'x' element in your array,
    //==> If recursion give us -1, then that means there is no 'x' element in recursion's array, So now
    //we check our element, if it is equal to 'x' then return index(start) otherwise return -1.
    //==> If Recursion give us number(not -1), then it means recursion find 'x' elements last index,
    //So now we just return recursion answer
    int ans{lastIndexHelp(arr,start+1,end,x)};
    if(ans == -1){
        if(arr[start] == x){
            return start;
        }
        return -1;
    }
    return ans;
}


int lastIndex(int* arr, int n, int x){
    return lastIndexHelp(arr,0,n-1,x);
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
    cout << lastIndex(arr,n,x) << endl;
    delete arr;
}