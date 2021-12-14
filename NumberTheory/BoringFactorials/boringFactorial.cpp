#include<iostream>
using std::cin;
using std::cout;
using std::endl;

long long power(long long a, long long b, long long c) {
    long long ans{1LL};
    while (b > 0) {
        if (b & 1) ans = (ans * a) % c;
        a = (a * a) % c;
        b = b >> 1;
    }
    return ans;
}

int main() {
    long long n, p, ans, factorial;
    int t;
    cin >> t;
    while (t--) {
        factorial = 1;
        cin >> n >> p;
        if (n >= p) {
            cout << 0 << endl;
            continue;
        }

        for (int i{n + 1}; i <= p - 1; i++) {
            factorial = (factorial * i) % p;
            if (factorial == 0) break;
        }

        ans = power(factorial, p - 2, p);
        cout << p - ans << endl;
    }
}
