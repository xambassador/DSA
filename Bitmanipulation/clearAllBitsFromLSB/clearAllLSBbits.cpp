#include<iostream>
using namespace std;
 

int clearAllLSB(int n, int i) {
    if(n == 0) return 0;
    n = n & (~((1 << (i+1))-1));
    return n;
}


int main() {
    int n;
    cin >> n;
    int i;
    cin >> i;
    n = clearAllLSB(n,i);
    cout << n << endl;
}