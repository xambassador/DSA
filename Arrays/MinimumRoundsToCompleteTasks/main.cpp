#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int calculateMinRounds(int items) {
    int minRounds {};
    if (items == 1) return -1;
    if (items == 2 || items == 3) return 1;
    // If item count is divisor of 3.
    if (items % 3 == 0) {
        minRounds += items / 3;
    } else {
        int reminder {items % 3};
        int divisor {items / 3};
        // If reminder is even, then we can use 2 taks to process so we can achive minimum rounds
        if (reminder % 2 == 0) {
            minRounds += divisor + (reminder / 2);
        } else {
            // If reminder is odd. Then Use total divisor - 1 of 3 taks.
            // Example: if items are 10. Then 10 / 3 = 3 and reminder is 1.
            // So, We process 3 tasks 2 times which is equal to (3*2) = 6;
            // And reminder become 4. Because we substract one group of 3 tasks from 10 / 3.
            // So, Now reminder become 3 + (10 % 3) which is equal to 4
            divisor -= 1;
            reminder += 3;
            minRounds += divisor + (reminder / 2);
        }
    }
    return minRounds;
}

// -----------------------------------------------------------------------------
// ----
// Time Complexity: O(nlog(n))
// Space Complexity: O(1)
int minimumRounds(vector<int>& tasks) {
    // Base Cases
    if (tasks.size() == 0) return -1;
    if (tasks.size() == 1) return -1;
    if (tasks.size() == 2) {
        if (tasks[0] == tasks[1]) return 1;
        return -1;
    }
    // Sort Input Array
    sort(tasks.begin(), tasks.end());
    int minRounds {};
    int i{}, j{1};
    while (i < tasks.size() && j < tasks.size()) {
        if (tasks[i] == tasks[j]) {
            j++;
            continue;
        }
        int items {((j - 1) - i) + 1}; // Count of element at tasks[i] is [(j-1), i]
        int rounds {calculateMinRounds(items)};
        if (rounds == -1) return -1;
        minRounds += rounds;
        i = j;
        j++;
    }
    int items {((j - 1) - i) + 1};
    int rounds {calculateMinRounds(items)};
    if (rounds == -1) return -1;
    minRounds += rounds;

    return minRounds;
}

// -----------------------------------------------------------------------------
int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i{}; i < n; i++) cin >> arr[i];
    cout << minimumRounds(arr) << endl;
}
