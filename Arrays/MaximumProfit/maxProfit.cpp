#include<iostream>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

int maxProfit(int budgetArray[], int n) {
    // 1. Sort the budget Array
    sort(budgetArray,budgetArray + n);

    /*
    2. Now We iterate over this budget array, So from starting to end, the budget of buyers is increase
    So for our app price, we choose every buyers budget as our app price one by one because budget array is sorted, if we choose arr[0]
    price then from arr[1] to arr[n-1] indexed buyers can buy app
     */

    int maxProfit{};
    for(int i{}; i < n; i++) {
        int setPriceToApp{budgetArray[i]};
        int totalBuyers{n - i};
        int profit{setPriceToApp * totalBuyers};
        if(profit > maxProfit) maxProfit = profit;
    }
    return maxProfit;
}

int main() {
    int n, budgetArray[1000000];
    cin >> n;
    for(int i{}; i < n; i++) cin >> budgetArray[i];
    cout << maxProfit(budgetArray,n) << endl;
}
