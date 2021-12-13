#include<iostream>
using std::cin;
using std::cout;
using std::endl;

bool isSet(int n, int position) {
    bool bit {n & (1 << position)};
    return bit;
}

int main() {
    int n, position;
    cin >> n >> position;
    cout << isSet(n, position);
}
