#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int turnOffFirstSetBit(int n) {
    if(n == 0) return 0;

    int position{}, i{};
    while(i < 32) {
        int num{n & (1 << i)};
        if(num == 0) position++;
        else break;
        i++;
    }
    n = n ^ (1<<position);
    return n;
}

int main() {
    int n;
    cin >> n;
    n = turnOffFirstSetBit(n);
    cout << n << endl;
}
