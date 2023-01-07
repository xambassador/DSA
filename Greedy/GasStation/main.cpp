#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n {(int)gas.size()};
    int start {};
    int total {};
    int tank {};
    for (int i{}; i < n; ++i) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            total += tank;
            tank = 0;
        }
    }
    return (total + tank < 0) ? -1 : start;
}

// -----------------------------------------------------------------------------
int main () {
    vector<int> gas {1, 2, 3, 4, 5};
    vector<int> cost {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}
