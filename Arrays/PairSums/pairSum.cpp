#include <iostream>
#include <climits>
using std::cin;
using std::cout;
using std::endl;

int pairSum(int arr[], int n, int x) {
    int ans {};
    for (int i{}; i < n; i++) {
        for (int j{i + 1}; j < n; j++) if (arr[i] + arr[j] == x) ans++;
    }
    return ans;
}

int main () {
    int testCase {}, n {}, arr[1000] {}, x {};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i{}; i<n; i++) cin >> arr[i];
        cin >> x;
        int numberOfPairs {pairSum(arr, n, x)};
        cout << numberOfPairs << endl;
    }
}
