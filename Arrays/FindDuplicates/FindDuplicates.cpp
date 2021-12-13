#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

// O(nlogn)
int findDuplicate_2(int arr[], int n) {
    sort(arr, arr+n);

    for (int i{}, j{1}; i < n && j < n; i++, j++) {
        if (arr[i] == arr[j]) return arr[i];
    }

    return -1;
}

// O(n^2)
int findDuplicate(int arr[], int n) {
    for (int i{}; i < n; i++) {
        bool isCurrentElementFound {false};

        for (int j{}; j < n; j++) {
            if (i == j) continue;
            if (arr[i] == arr[j]) {
                isCurrentElementFound = true;
                break;
            }
        }

        if (isCurrentElementFound) return arr[i];
    }

    return -1;
}


int main () {
    int n{}, arr[1000]{}, ans{-1};
    cin >> n;

    for (int i{}; i < n; i++) cin >> arr[i];

    ans = findDuplicate(arr, n);
    cout << ans << endl;
    ans = findDuplicate_2(arr, n);
    cout << ans << endl;
}
