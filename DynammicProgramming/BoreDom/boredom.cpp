#include<iostream>
#include<vector>
using namespace std;
 
int solve(int n, vector<int>& a) {
    int frequancy[1005];
    int dp[1005];
    for(int i{};i<1005; i++) {
        dp[i] = 0;
        frequancy[i] = 0;
    }
    for(int i{}; i<n; i++) {
        frequancy[a[i]]++;
    }
    dp[0] = 0;
    dp[1] = frequancy[1];
    for(int i{2}; i<=1000; i++) {
        dp[i] = max(dp[i-2]+i*frequancy[i], dp[i-1]);
    } 
    int ans {dp[1000]};
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> a;
    for(int i{}; i<n; i++) {
        int data;
        cin >> data;
        a.push_back(data);
    }
    int ans {solve(n,a)};
    cout << ans << endl;
}