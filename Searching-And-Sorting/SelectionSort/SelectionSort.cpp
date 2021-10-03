#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::swap;

int findSmallElementIndex(int arr[], int n, int start) {
    int smallElement {arr[start]}, smallElementIndex {start};
    for (int i{start+1}; i<n; i++) {
        if (arr[i] < smallElement) {
            smallElement = arr[i];
            smallElementIndex = i;
        }
    }
    return smallElementIndex;
}

// Recursive Selection sort

// If we call recursion first
void selectionSortRecursive2(int arr[], int n) {
    // Base case
    if (n == 0 || n == 1) return;
    
    // Call Recursion
    selectionSortRecursive2(arr+1, n-1);

    // Doing my job, which is find smallest element and swap it with my element
    int smallElementIndex {findSmallElementIndex(arr, n, 0)};
    swap(arr[0], arr[smallElementIndex]);

    // Call recursion
    selectionSortRecursive2(arr+1, n-1);
}

// If i do my job first.
void selectionSortRecursive(int arr[], int n) {
    // Base case
    if (n == 0 || n == 1) return;
    
    // Doing my job, which is find smallest element and swap it with my element
    int smallElementIndex {findSmallElementIndex(arr, n, 0)};
    swap(arr[0], arr[smallElementIndex]);

    // Call recursion
    selectionSortRecursive(arr+1, n-1);
}


// Iterative solution : O(n^2)
void selectionSort(int arr[], int n) {
    for (int i{}; i<n; i++) {
        int smallElementIndex {findSmallElementIndex(arr,n,i)};
        swap(arr[i], arr[smallElementIndex]);
    }
}

int main () {
    int n{}, arr[1000000]{};
    cin >> n;

    for (int i{}; i<n; i++) cin >> arr[i];

    // selectionSort(arr, n);
    selectionSortRecursive(arr, n);
    // selectionSortRecursive2(arr, n);

    for (int i{}; i<n; i++) cout << arr[i] << " ";

}
