#include <iostream>
using namespace std;

bool isSorted (int* arr, int n) {
    // base case
    if (n == 0 || n == 1) return true;

    bool recursionAns {isSorted(arr+1,n-1)};

    if (arr[0] < arr[1] && isSorted(arr+1, n-1)) return true;
    else return false;
}

int main () {
    int n;
    cin >> n;

    int arr[n];
    for (int i{}; i<n; i++) cin >> arr[i];

    bool ans {isSorted(arr, n)};
    cout << boolalpha << ans << endl;
}