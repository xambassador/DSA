#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// ---- Provided by Leetcode
bool isBadVersion(int version) {}

// -----------------------------------------------------------------------------
// ----
// Time complexity: O(log(n))
// Space complexity: O(1)
int find(int start, int end) {
    if (start > end) return -1;
    if (start == end) {
        return isBadVersion(start) ? start : -1;
    }
    // ----
    // Calculating Mid element in correct way is important as it can lead overflow issues.
    // https://en.wikipedia.org/wiki/Binary_search_algorithm#Implementation_issues
    int mid {start + (end - start) / 2};
    if (isBadVersion(mid)) {
        return find(start, mid);
    }
    return find(mid + 1, end);
}

// -----------------------------------------------------------------------------
int firstBadVersion(int n) {
    if (n == 1) return 1;
    return find(1, n);
}

// -----------------------------------------------------------------------------
int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i{}; i < n; i++) arr[i] = i + 1;
}
