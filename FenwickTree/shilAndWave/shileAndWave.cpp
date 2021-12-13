#include<iostream>
using std::cin;
using std::cout;
using std::endl;

const int MOD {1000000007};

int main() {
    long long n, x, t, sum1, sum2;
    cin >> n;
    long long dpl[100001]{}, dph[100001]{}, arr[100001]{};
    for (long long i{1}; i < n + 1; i++) {
        cin >> x;
        t = 100000;
        sum1 = 0;
        sum2 = 0;
        while(t) {
            sum1 = (sum1 + dph[t] + arr[t]) % MOD;
            t -= (t & (-t));
        }
        t = x;
        while(t) {
            sum1 = (sum1 - dph[t] - arr[t] + MOD) % MOD;
            t -= (t & (-t));
        }
        t = x - 1;
        while(t) {
            sum2 = (sum2 + dpl[t] + arr[t]) % MOD;
            t -= (t & (-t));
        }
        t = x;
        while(t < 100001) {
            dpl[t] = (dpl[t] + sum1) % MOD;
            dph[t] = (sum2 + dph[t]) % MOD;
            arr[t] += 1;
            t += (t & (-t));
        }
    }

    long long ans {};
    sum1 = 0;
    sum2 = 0;
    t = 100000;
    while(t) {
        ans = (ans + dph[t]) % MOD;
        ans = (ans + dpl[t]) % MOD;
        t -= (t & (-t));
    }
    cout << ans;
}
