#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::max;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int maxBags{};
    vector<int> remainingRocks(capacity.size());
    for (int i{}; i < capacity.size(); i++) remainingRocks[i] = capacity[i] - rocks[i];
    sort(remainingRocks.begin(), remainingRocks.end());

    for (int i{}; i < remainingRocks.size(); i++) {
        if (additionalRocks >= remainingRocks[i]) {
            additionalRocks -= remainingRocks[i];
            maxBags++;
        } else {
            break;
        }
    }

    return maxBags;
}

// -----------------------------------------------------------------------------
int main() {
    int n, m, additionalRocks;
    cin >> n;
    vector<int> capactiy(n);
    for (int i{}; i < n; i++) cin >> capactiy[i];
    cin >> m;
    vector<int> rocks(m);
    for (int i{}; i < m; i++) cin >> rocks[i];
    cin >> additionalRocks;
    cout << maximumBags(capactiy, rocks, additionalRocks) << endl;
}
