
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int linearSearch(int arr[], int size, int searchElement) {
    // Lets search for searchElement
    for (int index{}; index<size; index++) {
        // Ok, we find element just return index.
        if (arr[index] == searchElement) return index;
    }

    // Ohh, we dont find any thing so lets return -1
    return -1;
}

int main () {
    int testCase{}, n{}, arr[1000000]{}, searchElement{};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i{}; i<n; i++) cin >> arr[i];
        cin >> searchElement;

        int ans {linearSearch(arr, n, searchElement)};
        cout << ans << endl;
    }
}
