#include <iostream>
#include <vector>
#include <algorithm>
using std::min;
using std::max;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int maxProfitBruteForce(vector<int>& prices) {
    int max {};
    // O(n ^ 2)
    for (int i{}; i < prices.size(); i++) {
        int buyStock {prices[i]};
        for (int j{i + 1}; j < prices.size(); j++) {
            int profit {prices[j] - buyStock};
            if (profit >= max) max = profit;
        }
    }
    return max;
}

// -----------------------------------------------------------------------------
int maxProfiltDP(vector<int>& prices) {
    if (prices.size() == 1) return 0;
    int maxProfitTillNow {};
    int minimumPriceOfStock {prices[0]};
    for (int i{}; i < prices.size(); i++) {
        // Check minimumPriceOfStock is less then current stock price.
        // If it is, then we can achive maximum profit till now.
        maxProfitTillNow = max(prices[i] - minimumPriceOfStock, maxProfitTillNow);
        minimumPriceOfStock = min(prices[i], minimumPriceOfStock);
    }

    return maxProfitTillNow;
}

// -----------------------------------------------------------------------------
int maxProfit(vector<int>& prices) {
    // return maxProfitBruteForce(prices);
    return maxProfiltDP(prices);
}

// -----------------------------------------------------------------------------
int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i{}; i < n; i++) cin >> arr[i];
    cout << maxProfit(arr) << endl;
}
