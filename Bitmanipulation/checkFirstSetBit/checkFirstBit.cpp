#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int returnFirstSetBit(int n) {
    if(n == 0) return 0;

    int i{}, position{};
    while(i < 32) {
        int num{n & (1 << i)};
        if(num == 0) position++;
        else break;
        i++;
    }

    int ans{1 << position};
    return ans;
}

int main() {
    int n;
    cin >> n;
    int ans{returnFirstSetBit(n)};
    cout << ans << endl;
}
