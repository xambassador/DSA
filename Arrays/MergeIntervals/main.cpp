#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
using std::sort;
using std::max;
using std::min;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

bool comparator(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

// -----------------------------------------------------------------------------
bool isIntervalOverlap(int& a1, int& a2, int& b1, int& b2) {
    int minimum {min(b1, b2)};
    if (minimum >= a1 && minimum <= a2) return true;
    return false;
}

// -----------------------------------------------------------------------------
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> output;
    int size {(int)intervals.size()};
    if (size == 0) return output;
    if (size == 1) {
        output.push_back(intervals[0]);
        return output;
    }

    // sort intervals
    sort(intervals.begin(), intervals.end(), comparator);

    vector<int> initialInterval {intervals[0]};
    for (int i{1}; i < size; i++) {
        // check if intervals are overlap.
        if (isIntervalOverlap(initialInterval[0], initialInterval[1], intervals[i][0], intervals[i][1])) {
            int minimum {min(min(initialInterval[0], initialInterval[1]), min(intervals[i][0], intervals[i][1]))};
            int maximum {max(max(initialInterval[0], initialInterval[1]), max(intervals[i][0], intervals[i][1]))};
            vector<int> mergeInterval {minimum, maximum};
            initialInterval = mergeInterval;
        } else {
            output.push_back(initialInterval);
            initialInterval = intervals[i];
        }
    }

    output.push_back(initialInterval);
    return output;
}

int main() {
    vector<vector<int>> intervals;

    int n;
    cin >> n;
    for (int i{}; i < n; i++) {
        vector<int> tmp{0, 0};
        cin >> tmp[0];
        cin >> tmp[1];
        intervals.push_back(tmp);
    }

    vector<vector<int>> output {merge(intervals)};
    for (int i{}; i < output.size(); i++) {
        cout << "[" << output[i][0] << ", " << output[i][1] << "]" << endl;
    }
}
