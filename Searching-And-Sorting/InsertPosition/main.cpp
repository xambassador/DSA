#include <vector>
using std::vector;
// -----------------------------------------------------------------------------------------

int helper(vector<int>& nums, int start, int end, int target) {
    // If start is greater than end, then we have reached the end of the array
    if (start > end) return start;

    if (start == end) {
        return nums[start] >= target ? start : start + 1;
    }

    int mid {start + (end - start) / 2};

    if (nums[mid] == target) return mid;
    if (nums[mid] <= target) return helper(nums, mid + 1, end, target);
    return helper(nums, start, mid - 1, target);
}

int searchInsert(vector<int>& nums, int target) {
    return helper(nums, 0, nums.size() - 1, target);
}
