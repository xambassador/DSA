#include<iostream>
using std::cin;
using std::cout;
using std::endl;
const int MOD {100000000 + 7};
typedef long long int ll;

void fillSeive(ll* arr, ll n) {
    ll* seive {new ll[750001]};
    for (int i{}; i < 750001; i++) seive[i] = 0;
    for (int i{}; i < n; i++) seive[arr[i]] = 1;
    for (int i{1}; i < 750001; i++) {
        ll currentElement {i};
        if (seive[currentElement] != 0) {
            for (int j{2}; j * currentElement < 750001; j++) {
                if (seive[j*currentElement] != 0) seive[j*currentElement] = (seive[j*currentElement] % MOD + seive[i] % MOD) % MOD;
            }
        }
    }
    ll sum {};
    for (int i{}; i < 750001; i++) sum = (sum % MOD + seive[i] % MOD) % MOD;
    cout << sum << endl;
    delete [] seive;
}

int main() {
    ll t;
    cin >> t;
    ll* arr {new ll[750001]};
    while(t--) {
        ll n;
        cin >> n;
        for (int i{}; i < n; i++) cin >> arr[i];
        fillSeive(arr,n);
    }
    delete [] arr;
}
