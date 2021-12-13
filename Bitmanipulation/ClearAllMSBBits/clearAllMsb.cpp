#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int clearMSB(int n, int i) {
    if(n == 0) return 0;
    n = n & (((1 << i) - 1));
    return n;
}

int main() {
    int n, i;
    cin >> n >> i;
    n = clearMSB(n, i);
    cout << n << endl;
}
