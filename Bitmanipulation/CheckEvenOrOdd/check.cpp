#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void check(int n) {
    if((n & (1 << 0)) == 0) cout << "even" << endl;
    else cout << "Odd" << endl;
}

int main() {
    int n;
    cin >> n;
    check(n);
}
