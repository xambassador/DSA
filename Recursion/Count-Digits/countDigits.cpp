#include<bits/stdc++.h>
using namespace std;

int count(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return 1+count(n/10);
}

int main(){
    int n;
    cin >> n;
    cout << count(n) << endl;
}