#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int power(long long int a, string b, int m) {
    int len{(int) b.length()};
    long long int ans{1};
    for (int i{len - 1}; i >= 0; i--) {
        if (b[i] == '0') {
            a = a % m;
            a = (((a * a) % m) * a) % m;
        } else if (b[i] == '1') {
            ans = ans * a;
            ans %= m;
            a = (((a * a) % m) * a) % m;
        } else if (b[i] == '2') {
            ans = ((ans * a) % m) * a;
            ans %= m;
            a = (((a * a) % m) * a) % m;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        // Base 10
        long long int a;
        cin >> a;

        // Base 3
        string b;
        cin >> b;

        // Base 10
        int m;
        cin >> m;

        cout << power(a,b,m) << endl;
    }
}
