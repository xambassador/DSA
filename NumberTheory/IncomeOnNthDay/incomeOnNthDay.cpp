#include<iostream>
using namespace std;
#define ll long long
#define MOD 1000000007

ll fibonaci(ll n) {
    if (n == 0 || n == 1 || n == 5) return n;
    if (n == 2) return 1;
    n--;
    ll arr[2][2] {1,1,1,0};
    ll ans[2][2] {1,0,0,1};
    ll temp[2][2];
    ll m {MOD - 1};
    while (n) {
        if (n & 1) {
            for (int i{}; i<2; i++) {
                for (int j{}; j<2; j++) {
                    temp[i][j] = 0;
                    for (int k{}; k<2; k++) {
                        temp[i][j] += arr[i][k] * ans[k][j];
                        temp[i][j] %= m;
                    }
                }
            }
            for (int i{}; i<2; i++) {
                for (int j{}; j<2; j++) ans[i][j] = temp[i][j];
            }
        }

        for (int i{}; i<2; i++) {
            for (int j{}; j<2; j++) {
                temp[i][j] = 0;
                for (int k{}; k<2; k++) {
                    temp[i][j] += arr[i][k] * arr[k][j];
                    temp[i][j] %= m;
                }
            }
        }

        for (int i{}; i<2; i++) {
            for (int j{}; j<2; j++) arr[i][j] = temp[i][j];
        }

        n >>= 1;
    }
    return ans[0][0];
}

ll power(ll a, ll b) {
    ll ans {1};
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    ll a,b,c,n,x,y;
    while (t--) {
        cin >> a >> b >> n;
        if (n == 0) cout << a << endl;
        else if (n == 1) cout << b << endl;
        else {
            x = fibonaci(n-1);
            y = fibonaci(n);
            c = power(a+1,x) * power(b+1,y);
            c--;
            c = c % MOD;
            if (c < 0) c += MOD;
            cout << c << endl;
        }
    }
}