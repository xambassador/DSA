#include<iostream>
using namespace std;

long arr[10000];


long staircase(int n) {

    if(n == 0 || n == 1) {
        arr[n] = 1;
        return 1;
    }
    else if(n == 2) {
        arr[n] = 2;
        return 2;
    }else {
        if(arr[n] > 0) {
            return arr[n];
        }
        long a1 {staircase(n-1)};
        long a2 {staircase(n-2)};
        long a3 {staircase(n-3)};
        arr[n] = a1+a2+a3;
        return arr[n];
    }

}

long stairCase_DP (int n) {
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i{3}; i<n+1; i++) {
        dp[i] = 0;
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int ans = dp[n];
    return ans;
}   


int main() {
    int n;
    cin >> n;
    for(int i{}; i<n; i++) {
        arr[i] = 0;
    }
    long ans {staircase(n)};
    cout << ans << endl;
    cout << stairCase_DP(n) << endl;
}