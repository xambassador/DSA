#include<iostream>
#include<cstring>
using std::cin;
using std::cout;

const int mod = 1000000000 + 7;

long long count(int n, int* ans) {
    if(n == 1 || n == 0) return 1;

	if(ans[n] > 0) return ans[n];

	long long cnt{};
	for(int i{1}; i <= n; i++) {
		long long left{count(i - 1, ans) % mod};
		ans[i - 1] = left;
		long long right{count(n - i, ans) % mod};
		ans[n - i] = right;
		cnt += (left * right) % mod;
	}
	ans[n] = cnt;
	return cnt;
}

int countBST(int n) {
    int* arr{new int[10000]};
    int ans{count(n, arr) % mod};
    delete [] arr;
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countBST(n);
}
