#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int maxPoints(vector<vector<int>>& points) {
    // Size of the vector
    int n {(int)points.size()};
    // If the size is less than 3, return the size of the vector
    // because there is no way to have a line with less than 3 points
    if (n < 3) return n;
    // Initialize the max to 0
    int max {};
    // Loop through the vector
    for (int i{}; i < n; i++) {
        // Initialize the same to 1
        int same{1};
        // Loop through the vector again starting from the next element
        for (int j{i + 1}; j < n; j++) {
            // Initialize the count
            int count{};
            // If the points are the same, increment the same
            if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                same++;
                continue;
            }
            // Loop through the vector
            for (int k{}; k < n; k++) {
                // If the points are the same at i and k, increment the count
                if (points[i][0] == points[k][0] && points[i][1] == points[k][1]) {
                    count++;
                    continue;
                }
                // If the points are the same at j and k, increment the count
                if (points[j][0] == points[k][0] && points[j][1] == points[k][1]) {
                    count++;
                    continue;
                }
                // Find the slope of the line between i and j and i and k and if they are the same, increment the count
                if ((points[i][0] - points[j][0]) * (points[i][1] - points[k][1]) == (points[i][0] - points[k][0]) * (points[i][1] - points[j][1])) {
                    count++;
                }
            }
            if (count > max) max = count;
        }
        if (same > max) max = same;
    }
    return max;
}

int main () {
    vector<vector<int>> points {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << maxPoints(points) << endl;
    return 0;
}
