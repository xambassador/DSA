#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swapAlternative(int arr[], int size) {
    for (int i{}, j{1}; i < size && j < size; i += 2, j += 2) {
        int tmp {arr[i]};
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

int main () {
    int testCase{}, n{}, arr[100000]{};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i{}; i < n; i++) cin >> arr[i];
        swapAlternative(arr, n);
        for (int i{}; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}
