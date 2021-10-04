#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int findTriplet(int arr[], int n, int x) {
    int ans {};
    for (int i{}; i<n; i++) {
        for (int j{i+1}; j<n; j++) {
            for (int k{j+1}; k<n; k++) {
                if (arr[i] + arr[j] + arr[k] == x) ans++;
            }
        }
    }

    return ans;
}


int main () {
    int testCase {}, n {}, arr[100] {}, x {};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i{}; i<n; i++) cin >> arr[i];
        cin >> x;
        int ans {findTriplet(arr, n, x)};
        cout << ans << endl;
    }
}
