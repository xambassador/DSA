#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int search(int* arr, int start, int end, int x) {
    if (start > end) return -1;
    // Calculating Mid element in correct way is important as it can lead overflow issues.
    // https://en.wikipedia.org/wiki/Binary_search_algorithm#Implementation_issues
    int mid {start + (end - start) / 2};
    if (arr[mid] == x) return mid;
    else if (x < arr[mid]) return search(arr, start, mid - 1, x);
    return search(arr, mid + 1, end, x);
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    int* arr {new int[n]};
    for (int i{}; i < n; i++) cin >> arr[i];
    int x;
    cin >> x;
    cout << search(arr, 0, n - 1, x) << endl;
}
