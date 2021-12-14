#include<iostream>
#define MAX 1000001
using std::cin;
using std::cout;
using std::endl;

int main() {
    long long int phi[MAX];
    long long int S[MAX], G[MAX];
    phi[1] = 1;
    for (int i{2}; i < MAX; i += 2) phi[i] = i / 2;
    for (int i{3}; i < MAX; i += 2) {
        if (!phi[i]) {
            phi[i] = i - 1;
            for (int j{i << 1}; j < MAX; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    for (int i{}; i < MAX; i++) S[i] = phi[i];
    for (int i{2}; i < MAX; i++) {
        for (int j{2}; j*i < MAX; j++) S[i*j] += j * phi[i];
    }

    G[1] = 0;
    for (int i{2}; i < MAX; i++) G[i] = G[i-1] + S[i];
    int n;
    while(1) {
        cin >> n;
        if (n == 0) break;
        cout << G[n] << endl;
    }
}
