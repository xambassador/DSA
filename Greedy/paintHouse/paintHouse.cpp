#include<iostream>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;

struct Workers {
    int time;
    int cost;
    int speed;
};

bool compare(Workers a, Workers b) {
    // If two workers available at same time
    if (a.time == b.time) {
        // then choose one which have maximum speed
        if (a.speed == b.speed) {
            // if speed is same then go with whose cost is less, because ultimatly we need to maintain minimum cost
            return a.cost < b.cost;
        }
        return a.speed > b.speed;
    }
    return a.time < b.time;
}

long long int minCost(Workers* arr, int n, long long d) {
    long long currentCost {arr[0].cost};
    long long areaCoverd {};
    int currentWorker {};

    for(int i{1}; i < n && areaCoverd < d; i++) {
        areaCoverd = areaCoverd + (arr[i].time - arr[i-1].time) * arr[currentWorker].speed;

        if(areaCoverd >= d) return currentCost;

        if (arr[currentWorker].speed < arr[i].speed) {
            currentWorker = i;
            currentCost += arr[currentWorker].cost;
        }
    }
    return currentCost;
}

int main() {
    int n;
    cin >> n;

    long long d;
    cin >> d;

    Workers* arr{new Workers[n]};
    for(int i{}; i < n; i++) cin >> arr[i].time >> arr[i].cost >> arr[i].speed;

    long long ans{minCost(arr, n, d)};
    cout << ans << endl;
}
