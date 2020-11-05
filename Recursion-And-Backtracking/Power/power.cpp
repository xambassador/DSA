#include<bits/stdc++.h>
using namespace std;
 
int Power(int x, int n){
    if(n == 0){
        return 1; 
    }
    int ans{Power(x,n-1)};
    return ans*x;
}

int main(){
    int x,n;
    cin >> x >> n;
    cout << Power(x,n) << endl;
}