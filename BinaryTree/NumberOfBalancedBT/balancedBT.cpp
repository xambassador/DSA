#include<iostream>
using namespace std;

const long long mod = 1000000000 + 7;


int balancedBTs(int h) {
    if(h == 0 || h == 1) return 1;

    long long int x = balancedBTs(h-1);
    long long int y = balancedBTs(h-2);
    long long int ans = x*x + 2*x*y;
    return ans%mod;
}



int main() {
    int n;
    cin >> n;
    int ans = balancedBTs(n);
    cout << ans << endl;
}