#include <vector>
#include <algorithm>
using std::vector;
using std::sort;
using std::greater;

// -----------------------------------------------------------------------------------------
// https://leetcode.com/problems/reducing-dishes/
int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());
    int n {(int)satisfaction.size()};
    int presum {}, res {};
    for (int i{}; i < n; i++) {
        presum += satisfaction[i];
        if (presum < 0) break;
        res += presum;
    }
    return res;
}
