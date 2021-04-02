#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#define MAX 1100001

long long int phi[MAX];
long long int p[300001];
long long int num[MAX];
bool primes[MAX];

int main() {
    int t;
    cin >> t;
    for (int i{3}; i<MAX; i++) primes[i] = 1;
    primes[2] = 1;
    for (int i{3}; i*i<MAX; i+=2) {
        if (primes[i]) {
            for (int j{i*i}; j<MAX; j+=2*i) primes[j] = 0;
        }
    }

    p[0] = 2;
    long long int c{1};
    for (int i{3};i<MAX; i+=2) {
        if (primes[i]) p[c++] = i;
    }

    while(t--) {
        int a,b,k;
        cin >> a >> b >> k;

        if (k == 1) {
            cout << fixed;
            cout << setprecision(6) << 1 << endl;
            continue;
        }

        for (int i{a}; i<=b; i++) {
            phi[i-1] = i;
            num[i-1] = i;
        }

        for (int i{}; p[i]*p[i] <= b; i++) {
            int base {a / p[i]*p[i]};
            while (base < a) base += p[i];
            while (base < p[i]) base += p[i];
            if (base == p[i]) base += p[i];
            for (int j{base}; j<=b; j+=p[i]) {
                while (num[j-1] % p[i] == 0) num[j-a] /= p[i];
                phi[j-a] -= phi[j-a] / p[i];
            }
        }

        for (int i{a}; i<=b; i++) {
            if (num[i-1] > 1) phi[i-a] -= phi[i-a] / num[i-a];
            num[i-a] = 1;
        }

        long long int c{};
        for (int i{a}; i<=b; i++ ) {
            if (phi[i-a] % k == 0) c++;
        }

        double ans {c};
        ans /= (b - a + 1);
        cout << fixed;
        cout <<  setprecision(6) << ans << endl;
    }
}