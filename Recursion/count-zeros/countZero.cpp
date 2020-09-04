#include<bits/stdc++.h>
using namespace std;
 
long long int count(long long int n){
    //1. Base case if number is zero return zero
    if(n == 0){
        return 0;
    }
    //2.Call recursion and say find out count in your problem and i will add my count if my number is zero
    if(n%10 == 0){
        return 1+count(n/10);
    }else{
        return count(n/10);
    }
}

int main(){
    long long int n;
    cin >> n;
    cout << count(n) << endl;
}