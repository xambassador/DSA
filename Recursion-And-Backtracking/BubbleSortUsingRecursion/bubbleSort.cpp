#include <iostream>
using namespace std;

// Bubble sort recursively - 1

void bubbleSortRec1 (int* arr, int size) {
    // base case
    if (size == 0 || size == 1) return;

    // Recursion part
    for (int j{}; j<size-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }

    bubbleSortRec1(arr, size-1);
} 


void bubbleSortRec2 (int* arr, int j, int n) {
    // base case
    if (n == 0 || n == 1) return;

    if (j == n - 1) return bubbleSortRec2(arr, 0, n-1);

    // Recursion part
    if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);

    bubbleSortRec2(arr, j+1, n);
    return;
}

int main () {
    int n;
    cin >> n;

    int arr[n];
    for (int i{}; i<n; i++) cin >> arr[i];

    // bubbleSortRec1(arr, n);
    bubbleSortRec2(arr,0, n);

    for (int i{}; i<n; i++) {
        cout << arr[i] << " ";
    }cout << endl;
}