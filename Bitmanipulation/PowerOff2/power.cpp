#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    for(int i{1}; i <= n; i++) {
        if((i & i-1) == 0) cout << i << " is power of 2" << endl;
    }
}
