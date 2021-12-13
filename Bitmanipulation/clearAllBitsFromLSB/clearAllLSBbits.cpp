#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int clearAllLSB(int n, int i) {
    if(n == 0) return 0;
    n = n & (~((1 << (i+1))-1));
    return n;
}

int main() {
    int n, i;
    cin >> n >> i;
    n = clearAllLSB(n, i);
    cout << n << endl;
}
