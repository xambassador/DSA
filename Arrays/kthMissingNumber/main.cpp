#include <iostream>
#include <vector>
using std::vector;

int findKthPositive(vector<int>& arr, int k) {
    int i {};
    int j {};
    int count {};
    while(i < arr.size()) {
        if (arr[i] != j + 1) {
            count++;
            if (count == k) {
                return j + 1;
            }
        } else {
            i++;
        }
        j++;
    }

    return j + k - count;
}
