#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

// ----
// Time Complexity: O (n * k); n = array size, k = each string length (which is equal)
// Space complexity: O (1)
int minDeletionSize(vector<string>& strs) {
    int columnSize {(int)strs[0].length()};
    int ans {};
    for(int col{}; col < columnSize; col++) {
        for (int row{1}; row < strs.size(); row++) {
            if (strs[row - 1][col] > strs[row][col]) {
                ans++;
                break;
            }
        }
    }
    return ans;
}

// -----------------------------------------------------------------------------
int main () {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i{}; i < n; i++) cin >> arr[i];
    cout << minDeletionSize(arr) << endl;
}
