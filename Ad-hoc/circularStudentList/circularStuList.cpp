#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int i, p;
        cin >> i >> p;
        int arr[12] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        int d{11 - i};
        int ans{};
        if (d < p) {
            int r = p - d;
            ans = arr[r - 1];
        } else {
            ans = arr[i + p];
        }
        cout << ans << endl;
    }
}
