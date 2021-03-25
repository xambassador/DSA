#include<iostream>
using namespace std;

class Triplet {
    public:
    int x;
    int y;
    int gcd;
};

Triplet extendedEuclide(int a, int b) {
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

int MMI(int a, int m) {
    Triplet ans {extendedEuclide(a,m)};
    return ans.x;
}

int main() {
    int a,m;
    cin >> a >> m;
    int ans {MMI(a,m)};
    cout << ans << endl;
}