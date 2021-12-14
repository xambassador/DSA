#include<iostream>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::min;

int main() {
    int n, k;
    cin >> n >> k;
    int* arr{new int[n]};
    for(int i{}; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int initialSmallDiff{arr[n - 1] - arr[0]};
    int small{arr[0] + k}, big{arr[n-1] - k};
    if (small > big) {
        int tmp{small};
        small = big;
        big = tmp;
    }
    for(int i{1}; i < n - 1; i++) {
        int sub{arr[i] - k}, add{arr[i] + k};
        if(sub >= small || add <= big) continue;
        if(big-sub <= add - small) small = sub;
        else big = add;
    }
    cout << min(initialSmallDiff, big - small) << endl;
}
