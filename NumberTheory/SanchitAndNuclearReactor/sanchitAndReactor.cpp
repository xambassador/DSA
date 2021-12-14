#include<iostream>
using std::cin;
using std::cout;
using std::endl;

long long fact(long long int a, int m) {
    long long int res {1};
    for (long long int i{2}; i<=a; i++) res = (res % m * i % m) % m;
    return res;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        long long int t;
        int m;
        cin >> t >> m;

        if (t<m) {
            if (m - t == 1) {
                cout << 1 << endl;
                continue;
            } else {
                cout << fact(t,m) << endl;
                continue;
            }
        } else {
            long long int last {t % m};
            long long int factorial {fact(last, m) % m};

            if ((t / m) % 2 == 0) cout << factorial << endl;
            else cout << ((m - 1) % m * factorial % m) % m << endl;
        }
    }
}
