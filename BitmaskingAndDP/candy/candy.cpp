#include<iostream>
using namespace std;
#define MAXN 16


int numWays(int like[][MAXN], int n, int child, int mask, int* dp) {
    if (child >= n) return 1;

    if (dp[mask] != 0) return dp[mask];

    int ans{};
    for (int i{}; i<n; i++) {
        if (!(mask & (1 << i)) && like[child][i]) {
            ans += numWays(like, n, child+1, (mask | (1 << i)) , dp);
        }
    }
    dp[mask] = ans;
    return ans;
}


long long solve(int like[][MAXN],int N) {
	int* dp {new int[1 << N]};
    for (int i{}; i<(1 << N); i++) dp[i] = 0;
    int ans {numWays(like, N, 0, 0, dp)};
    delete [] dp;
    return ans;
}

int main() {
	int n,like[MAXN][MAXN];
	cin>>n;
	for (int i{}; i < n ; i++) {
		for (int j{}; j < n; j++) {
			cin>>like[i][j];
		}
	}
	cout<<solve(like,n)<<endl;
}