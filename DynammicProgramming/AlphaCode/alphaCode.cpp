#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

const long long mod = 1000000000 + 7;

long long numCode(long long* arr, int n, long long* ans) {
    if(n == 0 || n == 1) return 1;
    if(ans[n] > 0) return ans[n];
    long long ans1 {0};
    if(arr[n-1] != 0) ans1 = {numCode(arr, n - 1, ans) % mod};

    if(arr[n-2]*10 + arr[n-1] <= 26 && arr[n-2] != 0) {
        ans1 += numCode(arr, n - 2, ans) % mod;
        ans1 %= mod;
    }
    ans[n] = ans1;
    return ans1;
}

int main() {
    while(1) {
        string s;
        cin >> s;
        if(s == "0") break;
        else {
            int size{int(s.size())};
            long long* arr{new long long[size]};
            long long* tmp{new long long[size+1]};
            for(int i{}; i < size; i++) {
                arr[i] = s[i] - '0';
                tmp[i] = 0;
            }
            tmp[size] = 0;
            long long ans{numCode(arr, size, tmp)};
            cout << ans << endl;
        }
    }
}
