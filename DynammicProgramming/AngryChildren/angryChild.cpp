#include<algorithm>
#include <iostream>
using std::cin;
using std::cout;
using std::sort;

int main() {
    int n, k;
    cin >> n >> k;

    long arr[n];
    for(int i{}; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    long old_cost{}, min_cost{}, sum{};

    for(int i{}; i < k; i++) {
        sum += arr[i];
        old_cost = old_cost + (i * arr[i]) - (k - 1 - i) * arr[i];
    }

    min_cost = old_cost;

    for(int i{k}; i < n; i++) {
        sum = sum - arr[i - k];
        old_cost = old_cost + (k-1) * (arr[i - k]) - (sum) + (k - 1) * (arr[i]) - sum;
        sum += arr[i];

        if(old_cost < min_cost) min_cost=old_cost;
    }
    cout << min_cost;
    return 0;
}
