#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int unset(int n, int i) {
    bool bit{n & (1 << i)};
    if(!bit) return n;
    n = n ^ (1 << i);
    return n;
}

int main() {
    int n, i;
    cin >> n >> i;
    int ans{unset(n, i)};
    cout << ans << endl;
}
