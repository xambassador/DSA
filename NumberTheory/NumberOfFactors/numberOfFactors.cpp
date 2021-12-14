#include<iostream>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;

void fillSeive(int* seive, int n) {
    for (int i{}; i < n + 1; i++) seive[i] = 0;
    for (int i{2}; i <= n; i++) {
        if (seive[i] == 0) for (int j{1}; j * i <= n; j++) seive[j * i] += 1;
    }
}

int main() {
    int t;
    cin >> t;
    int* seive {new int[1000001]};
    int** table {new int*[11]};
    for (int i{}; i<11; i++) table[i] = new int[10000001];
    fillSeive(seive,1000001);
    for (int i{}; i < 11; i++) {
        table[i][0] = 0;
        table[i][1] = 0;
        for (int j{2}; j < 1000001; j++) {
            if (i == seive[j]) table[i][j] = table[i][j-1] + 1;
            else table[i][j] = table[i][j-1];
        }
    }
    for (int i{1}; i <= t; i++) {
        int a,b,n;
        cin >> a >> b >> n;
        if (a == 1 && n == 0) {
            cout << 1 << endl;
            continue;
        }
        cout << table[n][b] - table[n][a-1] << endl;
    }
}
