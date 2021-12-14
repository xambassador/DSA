#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::greater;
using std::sort;

#define MAX_SIZE 2000001

int main() {
    int* sieve {new int[MAX_SIZE]};
    for (int i{}; i <= MAX_SIZE; i++) sieve[i] = i;
    for (int i{2}; i * i <= MAX_SIZE; i++) {
        for (int j{i * i}; j <= MAX_SIZE; j += i) {
            if (sieve[j] > i) sieve[j] = i;
        }
    }
    int n, k{};
    cin >> n;
    int* finalans {new int[n]};
    bool* marked  {new bool[n + 1]};
    for (int i{}; i <= n; i++) marked[i] = false;
    for (int i{n}; i >= 1; i--) {
        if (!marked[i]) {
            int lpd {sieve[i]};
            int x {i};
            vector<int> v;
            marked[i] = true;
            v.push_back(i);
            while (x != 1) {
                for (int j{i - lpd}; j >= 1; j = j - lpd) {
                    if (!marked[j]) {
                        marked[j] = true;
                        v.push_back(j);
                    }
                }
                while (x % lpd == 0) x = x / lpd;
                lpd = sieve[x];
            }

            sort(v.begin(), v.end(), greater<int>());
            for (int i{}; i < v.size(); i++) {
                finalans[k] = v[i];
                k++;
            }
        }
    }
    finalans[n - 1] = 1;
    for (int i{}; i < n; i++) cout << finalans[i] << " ";
    cout << endl;
}
