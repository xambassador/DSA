#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::greater;

vector<pair<int,int> > arr;
vector<pair<pair<int,int>, pair<int,int> > > queries;
int ans[200002], bit[30002];

int query(int r, int n) {
    int ans {};
    while(r > 0) {
        ans += bit[r];
        r -= (r & -r);
    }
    return ans;
}

void update(int i, int n) {
    while (i <= n) {
        bit[i]++;
        i += (i & -i);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i{1}; i <= n; i++) {
        int x;
        cin >> x;
        arr.push_back({x, i});
    }

    sort(arr.begin(), arr.end());

    int q;
    cin >> q;
    for (int i{1}; i <= q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        queries.push_back({{k,i}, {l,r}});
    }

    sort(queries.begin(), queries.end(), greater<pair<pair<int,int>, pair<int,int> > >());
    for (pair<pair<int,int>, pair<int,int> > p : queries) {
        int k{p.first.first};
        int i{p.first.second};
        int l{p.second.first};
        int r{p.second.second};
        int j{arr.size() - 1};
        while(j >= 0) {
            if (arr[j].first > k) {
                update(arr[j].second, n);
                arr.pop_back();
            } else break;
            j--;
        }
        int tmp{query(r, n) - query(l - 1, n)};
        ans[i] = tmp;
    }
    for (int i{1}; i <= queries.size(); i++) cout << ans[i] << endl;
    return 0;
}
