#include <vector>
#include <algorithm>
using std::min;
using std::vector;

 int maxArea(vector<int>& height) {
    int maxArea {};
    int left {};
    int right {(int)height.size() - 1};

    while (left < right) {
        int minHeight {min(height[left], height[right])};
        int area {(right - left) * minHeight};
        maxArea = area > maxArea ? area : maxArea;

        if (height[left] < height[right]) {
            do {
                left++;
            } while (left < right && height[left-1] >= height[left]);
        } else {
            do {
                right--;
            } while (right > left && height[right+1] >= height[right]);
        }
    }
    return maxArea;
}
