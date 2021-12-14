#include<iostream>
#include<utility>
#include<vector>
typedef long long int ll;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;

int main() {
    int n;
    ll k, ans{};
    cin >> n >> k;
    ll temp_for_k {k};
    vector<ll> a(n);
    for (int i{}; i < n; i++) cin >> a[i];
    // store prime factors of k with respective powers
    vector<pair<int,int> > v;
    for (int i{2}; i * i <= temp_for_k; i++) {
        if (temp_for_k % i == 0) {
            int count {};
            while (temp_for_k % i == 0) {
                temp_for_k /= i;
                count++;
            }
            v.push_back(make_pair(i, count));
        }
    }
    if (temp_for_k != 1) v.push_back(make_pair(temp_for_k, 1));

    //vq contains all prime factors of k with their respective powers 0
    vector<pair<int,int> > vq = v;
    for (int i{}; i < vq.size(); i++) vq[i].second = 0;
    int j {};
    for (int i {}; i < n; i++) {
        for (int z{}; z < v.size(); z++) {
            if (a[i] % v[z].first == 0) {
                temp_for_k = a[i];
                int cn {};
                while (temp_for_k % v[z].first == 0) {
                    temp_for_k /= v[z].first;
                    cn++;
                }
                vq[z].second += cn;
            }
        }
        while (j <= i) {
            int z;
            //check if divisible by k from j to i
            for (z = 0; z < v.size(); z++) if (v[z].second > vq[z].second) break;
            if (z != v.size()) break;
            // if divisible update ans
            ans += n - i;
            // remove factors of a[j] from vq
            for (int z{}; z < v.size(); z++) {
                if (a[j] % v[z].first == 0) {
                    temp_for_k = a[j];
                    int cn {};
                    while (temp_for_k % v[z].first == 0) {
                        temp_for_k /= v[z].first;
                        cn++;
                    }
                    vq[z].second -= cn;
                }
            }
            j++;
        }
    }
    cout << ans;
}
