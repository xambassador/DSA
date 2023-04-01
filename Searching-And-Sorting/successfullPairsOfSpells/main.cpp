#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

 vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int n {(int)spells.size()};
    int m {(int)potions.size()};
    vector<int> pairs(n, 0);
    sort(potions.begin(), potions.end());
    for (int i{}; i < n; i++) {
        int spell {spells[i]};
        int left {};
        int right {m - 1};
        while (left <= right) {
            int mid {left + (right - left) / 2};
            long long product {(long long)spell * (long long)potions[mid]};
            if (product >= success) right = mid - 1;
            else left = mid + 1;
        }
        pairs[i] = m - left;
    }
    return pairs;
}
