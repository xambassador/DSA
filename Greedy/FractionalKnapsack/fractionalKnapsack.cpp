#include<iostream>
#include<algorithm>

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double value1 {((double)a.value) / (a.weight)};
    double value2 {((double)b.value) / (b.weight)};
    return value1 > value2;
}

double fKnapsack(Item* arr, int n, int W) {
    std::sort(arr,arr+n,compare);
    int currentWeight {};
    double fValue {};

    for(int i{}; i<n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            fValue += arr[i].value;
        } else {
            int remainingWeight {W - currentWeight};
            fValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break;
        }
    }

    return fValue;
}

int main() {
    int n;
    std::cin >> n;
    Item arr[n];
    for(int i{}; i<n; i++) {
        std::cin >> arr[i].value >> arr[i].weight;
    }

    int W;
    std::cin >> W;
    double ans {fKnapsack(arr,n,W)};
    std::cout << ans << std::endl;
}