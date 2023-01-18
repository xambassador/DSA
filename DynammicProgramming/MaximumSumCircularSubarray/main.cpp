#include <iostream>
#include <vector>
#include <algorithm>
using std::max;
using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int maxSubarraySumCircular(vector<int>& nums) {
    // Describe solution here
    /*
    1. Find the maximum subarray sum using Kadane's algorithm
    2. Find the minimum subarray sum using Kadane's algorithm
    3. Find the total sum of the array
    4. If the maximum subarray sum is positive, return the maximum of the maximum subarray sum and the total sum minus the minimum subarray sum
    5. If the maximum subarray sum is negative, return the maximum subarray sum
    */
    int maxSum {nums[0]};
    int minSum {nums[0]};
    int totalSum {nums[0]};
    int currMax {nums[0]};
    int currMin {nums[0]};
    for (int i{1}; i < nums.size(); i++) {
        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(maxSum, currMax);
        currMin = min(nums[i], currMin + nums[i]);
        minSum = min(minSum, currMin);
        totalSum += nums[i];
    }
    if (maxSum > 0) return max(maxSum, totalSum - minSum);
    return maxSum;
}

int main () {
    vector<int> nums {-2, -3, -1};
    cout << maxSubarraySumCircular(nums) << endl;
    return 0;
}
