#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void fillSeive(int* seive) {
    for (int i{}; i < 1000001; i++) seive[i] = 0;
    seive[1] = 1;
    for (int i{2}; i <= 100; i++) {
        int currentCubicNumber{i * i * i};
        for (int j{1}; currentCubicNumber * j < 1000001; j++) seive[currentCubicNumber * j] = -1;
    }

    int k {1};
    for (int i{1}; i <= 1000000; i++) {
        if (seive[i] != -1) {
            seive[i] = k;
            k++;
        }
    }
}

int main() {
    int t;
    cin >> t;
    int* seive {new int[1000001]};
    fillSeive(seive);
    for (int i{1}; i <= t; i++) {
        int n;
        cin >> n;
        if (seive[n] != -1) cout << "Case " << i << ": " << seive[n] << endl;
        else cout << "Case " << i << ": " << "Not Cube Free" << endl;
    }
}
