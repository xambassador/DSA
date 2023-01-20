#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

// nums: nums is a vector of integers which is the input array
// start: start is an integer which is the index of the first element in the current path
// path: path is a vector of integers which is the current path. Path represents a non-decreasing subsequence
// result: result is a vector of vectors of integers which is the result of the function
// Time complexity: O(2^n)
// Space complexity: O(n)
void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result) {
    // If the path is not empty and the path is not a subsequence of the result, then add the path to the result
    if (path.size() > 1) {
        result.push_back(path);
    }
    // used is a vector of booleans which is used to avoid duplicates.
    // Here, we use the value 201 because the maximum value of the input array is 100 and the minimum value of the input array is -100.
    vector<bool> used(201, false);

    // For each element in the input array
    for (int i{start}; i < nums.size(); ++i) {
        // If the element is already used, then continue
        if (used[nums[i] + 100]) {
            continue;
        }

        // If the path is empty or the current element is greater than or equal to the last element in the path
        // then add the current element to the path and dalegate the task to recursion.
        if (path.empty() || nums[i] >= path.back()) {
            used[nums[i] + 100] = true;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, result);
            path.pop_back();
        }
    }
}

// -----------------------------------------------------------------------------------------
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    dfs(nums, 0, path, result);
    return result;
}

// -----------------------------------------------------------------------------------------
int main () {
    vector<int> nums{4, 6, 7, 7};
    vector<vector<int>> result {findSubsequences(nums)};
    for (auto& i: result) {
        for (auto& j: i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}
