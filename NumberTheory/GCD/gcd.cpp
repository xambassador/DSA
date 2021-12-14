#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::min;

int main() {
    int a, b;
    cin >> a >> b;
    int gcd {1};
    int n {min(a, b)};
    for (int i{1}; i <= n; i++) {
        if (a % i == 0 && b % i == 0) gcd = i;
    }
    cout << gcd << endl;
}
