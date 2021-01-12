#include<iostream>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    int k;
    std::cin >> k;
    int* arr {new int[n]};
    for(int i{}; i<n; i++) std::cin >> arr[i];
    std::sort(arr,arr+n);
    int initialSmallDiff {arr[n-1] - arr[0]};
    int small {arr[0] + k};
    int big {arr[n-1] - k};
    if (small > big) {
        int tmp {small};
        small = big;
        big = tmp;
    }
    for(int i{1}; i<n-1; i++) {
        int sub {arr[i] - k};
        int add {arr[i] + k};
        if(sub >= small || add <= big) continue;
        if(big-sub <= add - small) small = sub;
        else big = add;
    }
    std::cout << std::min(initialSmallDiff, big-small) << std::endl;
}