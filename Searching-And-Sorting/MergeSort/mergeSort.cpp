#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

void merge(int* arr, int start, int mid, int end) {
    int n {(mid - start) + 1};
    int m {end - mid};
    int l[n], r[n];
    for (int i{}; i < n; i++) l[i] = arr[start + i];
    for (int i{}; i < m; i++) r[i] = arr[mid + 1 + i];
    int i{}, j{}, k {start};
    while (i < n && j < m) {
        if (l[i] < r[j]) arr[k++] = l[i++];
        else arr[k++] = r[j++];
    }
    while (i < n) arr[k++] = l[i++];
    while (j < m) arr[k++] = r[j++];
}

void mergeSort(int* arr, int start, int end) {
    if (start < end) {
        // Calculating Mid element in correct way is important as it can lead overflow issues.
        // https://en.wikipedia.org/wiki/Binary_search_algorithm#Implementation_issues
        // This approach taken from above binary search algorithm link.
        int mid {start + (end - start) / 2};
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void Sort(int* arr, int n) {
    mergeSort(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    int* arr{new int[n]};
    for (int i{}; i < n; i++) cin >> arr[i];
    Sort(arr,n);
    for (int i{}; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}
