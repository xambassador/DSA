#include<bits/stdc++.h>
using namespace std;
 
int stair(int n){
    if(n == 0 || n == 1){
        return 1;
    }else if(n == 2){
        return 2;
    }else{
        return stair(n-1) + stair(n-2) + stair(n-3);
    }
}

int main(){
    int n;
    cin >> n;
    cout << stair(n) << endl;
}