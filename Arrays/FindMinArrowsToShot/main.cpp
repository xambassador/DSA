#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    int totalArrows {1};
    int last {points[0][1]};
    for (int i{1}; i < points.size(); i++) {
        if (points[i][0] > last) {
            totalArrows++;
            last = points[i][1];
        }
        last = min(points[i][1], last);
    }
    return totalArrows;
}

int main () {
    int rows;
    cin >> rows;
    vector<vector<int>> grid(rows);
    for (int i{}; i < rows; i++) {
        vector<int> arr(2);
        cin >> arr[0];
        cin >> arr[1];
        grid[i] = arr;
    }
    cout << findMinArrowShots(grid) << endl;
}
