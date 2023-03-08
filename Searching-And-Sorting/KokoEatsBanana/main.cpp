#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using std::ceil;
using std::vector;
using std::min_element;
using std::max_element;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

int minEatingSpeed(vector<int>& piles, int h) {
    int minElement {1};
    int maxElement = *max_element(piles.begin(), piles.end());
    int start {minElement};
    int end {maxElement};
    int k {};

    while (start <= end) {
        int mid {start + (end - start) / 2};
        long long int totalHours {0};
        for (int i{}; i < piles.size(); i++) {
            long long int hours {ceil((double)piles[i] / mid)};
            totalHours += hours;
        }

        if (totalHours <= h) {
            k = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return k;
}

int main() {
    vector<int> piles {3, 6, 7, 11};
    int h {8};
    cout << minEatingSpeed(piles, h) << endl;
    return 0;
}
