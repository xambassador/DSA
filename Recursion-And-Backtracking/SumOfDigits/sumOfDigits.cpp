#include<bits/stdc++.h>
using namespace std;
 
int sumOfDigits(int n){
    // 1. Base case, if number is zero, then sum is also zero
    if(n == 0){
        return 0;
    }
    return sumOfDigits(n/10)+n%10;
}

int main(){
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
}