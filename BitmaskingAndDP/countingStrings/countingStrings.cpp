#include <iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;
#define mod 1000000007
#define ll long long int

int countStrings(char* s) {
    int i{}, n{(int)strlen(s)};
    ll req{}, dp[100005], arr[100005], ans{};
    for (int i{}; i < n; i++) arr[i] = (ll)(90 - s[i]);
    dp[n - 1] = arr[n - 1];

    for (int i{n - 2}; i >= 0; i--) {
        req = (arr[i + 1] + (26 * req) % mod) % mod;
        dp[i] = (arr[i] + (arr[i] * req) % mod) % mod;
    }

    for (int i{}; i < n; i++) ans = (ans + dp[i]) % mod;
    ans = ans % mod;
    return ans;
}

int main(){
	char s[100005];
    cin >> s;
    int ans {countStrings(s)};
    cout << ans << endl;
}
