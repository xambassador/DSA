#include<iostream>
using namespace std;

// Time complexity = O(n * sqrt(n))

bool isPrime(int n) {
    int cnt {};
    for (int i{1}; i*i<=n; i++) {
        if (n % i == 0) {
            if (i*i == n) {
                cnt += 1;
            }else {
                cnt += 2;
            }
        }
    }

    if (cnt == 2) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    int cnt {};
    for (int i{1}; i<=n;i++) {
        if (isPrime(i)) cnt++;
    }
    cout << cnt << endl;
}