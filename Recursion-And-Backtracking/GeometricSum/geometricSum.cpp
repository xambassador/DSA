#include<bits/stdc++.h>
using namespace std;

float gSum(int k){
    //1. Base case, if k is zero
    if(k == 0){
        return 1;
    }
    return gSum(k-1)+1/pow(2,k);
}

int main(){  
    int n;
    cin >> n;
    cout << gSum(n) << endl;
}