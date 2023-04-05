#include <vector>
#include <algorithm>
using std::max;
using std::vector;

// https://leetcode.com/problems/minimize-maximum-of-array/
int minimizeArrayValue(vector<int>& nums) {
    long sum {}, res {};
    for (int i{}; i < nums.size(); ++i) {
        sum += nums[i];
        res = max(res, (sum + i) / (i + 1));
    }
    return res;
}
