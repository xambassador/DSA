#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
// -----------------------------------------------------------------------------

bool canJump(int* arr, int n) {
    // If array is empty or has one element. That means we are already done.
    if (n == 0 || n == 1) return true;

    // max store current maximum value at any given index.
    // To reach last index, we need maximum max, so at last index that max become either zero or non-zero.
    int max{};
    for (int i{}; i < n; i++) {
        // We found new maximum for reaching last index.
        if (max <= arr[i]) max = arr[i];

        // If current index is last index, then we need to return true, as we reach to last index.
        if (i == n - 1) return true;

        // If max is zero or it become zero. That means, we use all of the maximum power to reach current position.
        // Now, if the index we reach is last index, then we need to return true, otherwise we need to return false,
        // as we can not reach at last index because of we didn't find any maximum value that can capable for reaching
        // last index.
        if (max == 0) {
            // Check for last index.
            if (i == n - 1) return true;

            // Ohh, we use all maximum power, now we can not reach to last index.
            return false;
        }

        // we are jumping to next index, so we need to decrease our maximum power by one.
        max--;
    }

    // we reach here, that means we process all elements in array including last index.
    return true;
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    int arr[100000];
    for (int i{}; i < n; i++) cin >> arr[i];
    cout << boolalpha << canJump(arr, n) << endl;
}
