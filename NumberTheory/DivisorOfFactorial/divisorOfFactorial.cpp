#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
typedef long long int ll;

const int MOD {1000000000 + 7};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i{2}; i*i<=n; i++) {
            if (is_prime[i] && (long long) i*i <= n) {
                for (int j{i*i}; j<=n; j+=i) is_prime[j] = false;
            }
        }

        ll total_divisor {1};
        for (int i{}; i<=n; i++) {
            if (is_prime[i]) {
                ll sum {};
                for (int j{1}; pow(i,j) <= n; j++) sum += n / pow(i,j);
                total_divisor = (total_divisor % MOD * (sum + 1) % MOD) % MOD;
            }
        }
        
        cout << total_divisor << endl;
    }
}