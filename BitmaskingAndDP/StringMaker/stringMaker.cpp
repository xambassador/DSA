#include<iostream>
using namespace std;
#define mod 1000000007
typedef long long int ll;


int help(string a, string b, string c, ll*** dp) {
    int na {(int) a.length()};
    int nb {(int) b.length()};
    int nc {(int) c.length()};
    
    if (nc == 0) return 1;

    if (na <= 0 && nb <= 0) return 0;

    if (dp[na][nb][nc] > -1) return dp[na][nb][nc] % mod;
    
    ll ans {};

    for (int i{}; i<na; i++) {
        if (a[i] == c[0]) ans += help(a.substr(i+1), b, c.substr(1), dp) % mod;
    }

    for (int i{}; i<nb; i++) {
        if (b[i] == c[0]) ans += help(a, b.substr(i+1), c.substr(1), dp) % mod;
    }

    dp[na][nb][nc] = ans % mod;
    return ans % mod;
}

int solve(string a, string b, string c) {
    ll*** dp {new ll**[51]};
    for (int i{}; i<51; i++) {
        dp[i] = new ll*[51];
        for (int j{}; j<51; j++) {
            dp[i][j] = new ll[51];
            for (int k{}; k<51; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    ll ans {help(a,b,c,dp) % mod};

    for (int i{}; i<51; i++) {
        for (int j{}; j<51; j++) {
            delete [] dp[i][j];
        }
    }
    
    return ans;
}

int main() {
	string a,b,c;
	cin >> a >> b >>c;
	cout << solve(a,b,c) << endl;
}