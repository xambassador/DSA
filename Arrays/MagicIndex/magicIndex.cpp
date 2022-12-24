#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int getMagicIndex(int* arr, int size) {
    for (int i{}; i < size; i++) {
        if (i == arr[i]) return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[100000] {};
    for (int i{}; i < n; i++) cin >> arr[i];

    cout << getMagicIndex(arr, n) << endl;
}
