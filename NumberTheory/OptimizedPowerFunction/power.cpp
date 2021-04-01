#include<iostream>
using namespace std;

int power(int x, int n) {
    if (x == 0) return 0;

    if (n == 0) return 1;

    if (n == 1) return x;
    
    int ans;

    if (n % 2 == 0) {
        int tmp {power(x, n/2)};
        ans = tmp * tmp;
    } else {
        int tmp {power(x, n/2)};
        ans = tmp * tmp * x;
    }

    return ans;
}


int main() {
    int x,n;
    cin >> x >> n;
    int ans {power(x,n)};
    cout << ans << endl;
}