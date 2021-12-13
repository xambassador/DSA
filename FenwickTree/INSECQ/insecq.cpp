#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;
using std::sort;

int M {5000000}, n, k, tree[52][300001];

void update(int index, int value, int i) {
    while(index <= n) {
        tree[i][index] = (tree[i][index] + value) % M;
        index += index & (-index);
    }
}

int query(int index, int i) {
    int ans {};
    while(index > 0) {
        ans = (tree[i][index] + ans ) % M;
        index -= index & (-index);
    }
    return ans;
}

void compress(vector<int>& arr) {
    vector<int> b{arr};
    sort(b.begin(), b.end());
    unordered_map<int, int> m;
    for (int i{1}, c{1}; i <= n; i++) {
        if (m.find(b[i]) == m.end()) m[b[i]] = c++;
    }
    for (int i{1}; i <= n; i++) arr[i] = m[arr[i]];
}

int main() {
    cin >> n >> k;
    if (k == 1) {
        cout << n;
        return 0;
    }

    vector<int> a(n+1);
    for (int i{1}; i <= n; i++) cin >> a[i];
    compress(a);
    int ans {};
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= k; j++) {
            int p {(j == 1 ? 1 : query(a[i] - 1, j - 1))};
            update(a[i], p, j);
            if (j == k) ans = (ans + p) % M;
        }
    }
    cout << ans;
}
