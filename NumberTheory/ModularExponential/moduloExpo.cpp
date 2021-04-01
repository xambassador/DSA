#include<iostream>
using namespace std;


int moduloExpo(int x, int n, int c) {
    if (x == 0) return 0;

    if (n == 0) return 1;

    long ans;
    if ((n%2) == 0) {
        long smallAns {moduloExpo(x, n/2, c)};
        ans = (smallAns*smallAns) % c;
    } else {
        long smallAns {moduloExpo(x, n-1, c)};
        ans = (x % c);
        ans = (ans * smallAns) % c; 
    }

    return (int)((ans + c) % c);
}


int main() {
    int x,n,c;
    cin >> x >> n >> c;
    cout << moduloExpo(x,n,c);
}