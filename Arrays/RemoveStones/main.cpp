#include <iostream>
#include <vector>
#include <queue>
using std::priority_queue;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int minStoneSum(vector<int>& piles, int k) {
    int sum{};
    for (int i{}; i < piles.size(); i++) sum += piles[i];
    priority_queue<int> heap(piles.begin(), piles.end());
    while (k--) {
        int top{heap.top()};
        heap.pop();
        int remove{top / 2};
        sum -= remove;
        heap.push(top - remove);
    }
    return sum;
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i{}; i < n; i++) cin >> piles[i];
    int k;
    cin >> k;
    cout << minStoneSum(piles, k) << endl;
}
