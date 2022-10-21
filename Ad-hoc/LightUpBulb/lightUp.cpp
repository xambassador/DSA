#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ll n, x, y;
    string s;

    cin >> n >> x >> y;
    cin >> s;

    ll count{};
    if (s[0] == '0') count = 1;

    for(int i{1}; i < n; i++) if (s[i-1] == '1' && s[i] == '0') count++;

    if (count == 0) {
        cout << count << endl;
        return 0;
    }

    ll cost{(count - 1) * min(x,y) + y};
    cout << cost << endl;
}
