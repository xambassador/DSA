#include<iostream>
using namespace std;
 
int set(int n, int i) {
    // first check whether ith position have already 1
    bool bit = n & (1 << i);
    if(bit) {
        return n;
    }
    n = n | (1 << i);
    return n;
}


int main() {
    int n,i;
    cin >> n >> i;
    int ans {set(n,i)};
    cout << ans << endl;
}