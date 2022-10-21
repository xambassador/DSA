#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int arr[n];

    cin >> n;
    for (int i{}; i < n ; i++) cin >> arr[i];

    int cnt{};

    for (int i{n - 1}; i >= 2; i--) {
        if (arr[i] == i + 1) continue;
        else {
            if (arr[i - 1] == i + 1) {
                swap(arr[i], arr[i - 1]);
                cnt++;
            }
            else if(arr[i - 2] == i + 1) {
                swap(arr[i - 2],arr[i - 1]);
                swap(arr[i - 1], arr[i]);
                cnt += 2;
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if(arr[0] == 1 && arr[1] == 2) {
        cout << "YES" << endl;
        cout << cnt << endl;
    }

    else if(arr[0] == 2 && arr[1] == 1) {
        swap(arr[0], arr[1]);
        cnt++;
        cout << "YES" << endl;
        cout << cnt << endl;
    } else {
        cout << "NO" << endl;
    }
}
