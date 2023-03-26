#include <vector>
using std::vector;

// -----------------------------------------------------------------------------------------
// Leetcode: https://leetcode.com/problems/number-of-zero-filled-subarrays/
long long zeroFilledSubarray(vector<int>& nums) {
    long count {};
    long subarrayEndingAtIndex {};
    for (int i{}; i < nums.size(); i++) {
        if (nums[i] == 0) count = count + (++subarrayEndingAtIndex);
        else subarrayEndingAtIndex = 0;
    }
    return count;
}
