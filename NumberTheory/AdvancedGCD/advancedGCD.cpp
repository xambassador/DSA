#include<iostream>
using namespace std;


int gcd(int a, int b) {
    if (b == 0) return a;
    if (a < b) return gcd(b,a);
    return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        string b;
        cin >> b;
        if (a == 0) {
            cout << b << endl;
            continue;
        }
        
        int number {};
        for (int i{}; i<b.size(); i++) {
            int currentDigit {b[i] - '0'};
            number = ((number * 10) % a + (currentDigit % a)) % a;
        }
        cout << gcd(a,number) << endl;
    }
}