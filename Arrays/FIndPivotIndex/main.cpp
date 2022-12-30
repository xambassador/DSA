#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int pivotIndex(vector<int>& nums) {
    int size {(int)nums.size()};
    int leftSumArray[size], rightSumArray[size];
    int previousSum {};
    for (int i{}; i < size; i++) {
        leftSumArray[i] = previousSum;
        previousSum += nums[i];
    }
    previousSum = 0;
    for (int i{size - 1}; i >= 0; i--) {
        rightSumArray[i] = previousSum;
        previousSum += nums[i];
    }
    for (int i{}; i < size; i++) {
        if (leftSumArray[i] == rightSumArray[i]) return i;
    }
    return -1;
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i{}; i < n; i++) cin >> nums[i];
    cout << pivotIndex(nums) << endl;
}
