#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int maxIceCream(vector<int>& costs, int coins) {
    if (costs.size() == 0) return 0;
    sort(costs.begin(), costs.end());
    int maximumIcecreams {};
    for (int i{}; i < costs.size(); i++) {
        if (costs[i] <= coins) {
            maximumIcecreams++;
            coins -= costs[i];
        }
    }
    return maximumIcecreams;
}


int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i{}; i < n; i++) cin >> arr[i];
    int coins;
    cin >> coins;
    cout << maxIceCream(arr, coins) << endl;
}
