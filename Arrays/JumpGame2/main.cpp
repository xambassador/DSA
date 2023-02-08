#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

int jump(vector<int>& nums) {
    // If there is only one element, then return 0
    if (nums.size() == 1) return 0;
    // If there are only two elements, then minimum jumps will be 1
    if (nums.size() == 2) return 1;

    // needToChoose: The index of the element that we need to choose to jump
    int needToChoose {};
    // canReach: The index of the element that we can reach from the current index
    int canReach {};
    // jump: The number of jumps that we need to make
    int jump {};

    for (int i{}; i < nums.size(); i++) {
        // If canReach is less than the current index + the value of the current index element
        // that means we can reach a further index from the current index.
        if (canReach < i + nums[i]) {
            canReach = i + nums[i];
            // If canReach is greater than or equal to the last index, then we reach the last index
            // so we can return the number of jumps + 1. +1 because we need to add current jump into
            // calculation.
            if (canReach >= nums.size() - 1) return jump + 1;
        }

        // If the current index is equal to the index of the element that we need to choose to jump
        // then we need to choose the next element that we can reach from the current index.
        // and we need to do a jump.
        if (i == needToChoose) {
            needToChoose = canReach;
            jump++;
        }
    }

    return jump;
}

int main() {
    // vector<int> arr {2, 3, 1, 1, 4};
    vector<int> arr {2, 3, 0, 1, 4};
    cout << jump(arr) << endl;
}
