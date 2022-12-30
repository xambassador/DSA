#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

void solveRec(vector<int>& nums, int start, int end, vector<int>& output, int previousSum = 0) {
    if (start > end) return;
    int sum {nums[start] + previousSum};
    output[start] = sum;
    solveRec(nums, start + 1, end, output, sum);
}

// -----------------------------------------------------------------------------
vector<int> runningSumRec(vector<int>& nums) {
    vector<int> output(nums.size());
    solveRec(nums, 0, nums.size() - 1, output);
    return output;
}

// -----------------------------------------------------------------------------
vector<int> runningSum(vector<int>& nums) {
    int size {(int)nums.size()};
    if (size == 0) return {};
    if (size == 1) return nums;
    vector<int> result(size);
    result[0] = nums[0];
    for (int i{1}; i < size; i++) {
        result[i] = result[i - 1] + nums[i];
    }
    return result;
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i{}; i < n; i++) cin >> arr[i];
    vector<int> result {runningSum(arr)};
    for (int i{}; i < n; i++) cout << result[i] << " ";
    cout << endl;
    result = runningSumRec(arr);
    for (int i{}; i < n; i++) cout << result[i] << " ";
}
