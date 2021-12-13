#include<iostream>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

class Coder {
    public:
    int first;
    int second;
    int index;
};

bool compare(Coder a, Coder b) {
    return a.second < b.second;
}

void update(int* bit, int index, int value, int n) {
    for (; index <= n; index += index & (-index)) bit[index] += value;
}

int value(int* bit, int index) {
    int ans {};
    for (; index > 0; index -= index & (-index)) ans += bit[index];
    return ans;
}

int main() {
    int n;
    cin >> n;

    int arr[30001], last[1000001], bit[30001], q{};
    Coder query[200000];
    for (int i{1}; i <= n; i++) cin >> arr[i];
    cin >> q;
    for (int i{}; i < q; i++) {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }
    sort(query, query + q, compare);
    for (int i{}; i < 1000001; i++) last[i] = -1;
    int k{}, *ans{new int[q]}, total{};
    for (int i{1}; i <= n; i++) {
        if (last[arr[i]] != -1) update(bit, last[arr[i]], -1, n);
        else total++;
        update(bit, i, 1, n);
        last[arr[i]] = i;
        while(k < q && query[k].second == i) {
            ans[query[k].index] = total - value(bit, query[k].first - 1);
            k++;
        }
    }
    for (int i{}; i < q; i++) cout << ans[i] << endl;
    return 0;
}
