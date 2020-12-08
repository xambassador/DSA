#include<iostream>
#include<algorithm>


int main() {
    long long n, k;
    std::cin >> n >> k;
    long long arr[n];
    for(int i{}; i<n; i++) {
        std::cin >> arr[i];
    }

    // sort the array
    std::sort(arr,arr+n);
    

    // maintain sum. for ith element {sum = arr[0]+arr[1]+arr[2]+...+arr[i]}
    long long sum[n];
    sum[0] = arr[0];
    for(int i{1}; i<n; i++) {
        sum[i] = sum[i-1] + arr[i];
    }

    // Find unfairness cost for first k packates out on n packets.
    long long cost{0};
    for(int i{1}; i<k; i++) {
        cost += i*arr[i] - sum[i-1];
    }

    // create sliding window.
    int start{1};
    int end{k};
    long long oldCost {cost};

    while(end < n) {
        long long newCost {(oldCost - (2*sum[end-1])) + arr[start-1]*(k-1) + arr[end]*(k-1)};
        cost = std::min(oldCost, newCost);
        start++;
        end++;
    }


    std::cout << cost << std::endl;
}