#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int search(int* arr, int n, int x) {
    int start {};
    int end {n - 1};
    while (start <= end && start >= 0) {
        int mid {(start + end) / 2};
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    int* arr {new int[n]};
    for (int i{}; i < n; i++) cin >> arr[i];
    int x;
    cin >> x;
    cout << search(arr, n, x) << endl;
}
