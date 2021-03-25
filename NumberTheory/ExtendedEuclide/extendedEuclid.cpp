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

int main() {
    int a,b;
    cin >> a >> b;
    Triplet ans {extendedEuclide(a,b)};
    cout << ans.gcd << endl;
    cout << ans.x << endl;
    cout << ans.y << endl;
}