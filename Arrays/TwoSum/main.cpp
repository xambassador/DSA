#include <iostream>
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i{}; i < nums.size(); i++) {
        int diff {target - nums[i]};
        if (map.find(diff) != map.end()) {
            ans.push_back(map[diff]);
            ans.push_back(i);
        } else {
            map[nums[i]] = i;
        }
    }

    return ans;
}

// -----------------------------------------------------------------------------
int main () {
    vector<int> nums {2, 7, 11, 15};
    int target {9};
    vector<int> ans {twoSum(nums, target)};
}
