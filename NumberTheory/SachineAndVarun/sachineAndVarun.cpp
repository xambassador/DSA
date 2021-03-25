#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int ll;


class Triplet {
    public:
    ll x;
    ll y;
    ll gcd;
};

Triplet extendedEuclide(ll a, ll b) {
    if (b == 0) {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    
    Triplet smallAns {extendedEuclide(b, a%b)};
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}


ll multipleInverse(ll a, ll m) {
    ll ans {extendedEuclide(a,m).x};
    return (ans % m + m) % m;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a,b,d;
        cin >> a >> b >> d;
        
        if (d == 0) {
            cout << 1 << endl;
            continue;
        }

        ll g = __gcd(a,b);
        
        if (d % g != 0) {
            cout << 0 << endl;
            continue;
        }

        a /= g;
        b /= g;
        d /= g;

        ll y1 {((d % a) * multipleInverse(b,a)) % a};
        ll firstValue { d/b };
        if (d < y1 * b) {
            cout << 0 << endl;
            continue;
        }

        ll n {(firstValue - y1) / a};

        ll ans {n+1};
        cout << ans << endl;
    }
}