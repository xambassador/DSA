#include<iostream>
#define MAX 1000001
#define MOD 1000000007
using namespace std;


long long int modExponetitation(long long int a, long long int b) {
    long long ans {1};
    while(b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    long long factorial[MAX];
    factorial[0] = 1;
    for (int i{1}; i<MAX; i++) {
        factorial[i] = i * factorial[i-1];
        if (factorial[i] >= MOD) factorial[i] %= MOD;    
    }

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        if (k > n) {
            cout << endl;
            continue;
        }
        long long int ans;
        ans = modExponetitation(2, k);
        ans = (ans * factorial[n]) % MOD;
        ans = (ans * modExponetitation(factorial[k], MOD-2)) % MOD;
        ans = (ans * modExponetitation(factorial[n - k], MOD-2)) % MOD;
        cout << ans << endl;
    }

    return 0;
}