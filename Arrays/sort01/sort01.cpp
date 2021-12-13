#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Iterative
void sort01(int* arr, int n) {
    int i{}, j{n - 1};
    while(i < j) {
        if(arr[i] == 0 && arr[j] == 1) {
            i++;
            j--;
        } else if(arr[i] == 0 && arr[j] == 0) i++;
        else if(arr[i] == 1 && arr[j] == 0) {
            int tmp{arr[i]};
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        } else if(arr[i] == 1 && arr[j] == 1) j--;
    }
}

// Iterative solution 2
void sort01_1(int arr[], int n) {
    int nextZero {};

    for (int i{}; i < n; i++) {
        if (arr[i] == 0) {
            int tmp {arr[nextZero]};
            arr[nextZero] = arr[i];
            arr[i] = tmp;
            nextZero++;
        }
    }
}

void merge(int arr[], int start, int mid, int end) {
    int n {(mid - start) + 1}, m {(end - mid)};
    int left[n], right[m];

    for (int i{}; i<n; i++) left[i] = arr[i + start];
    for (int i{}; i<m; i++) right[i] = arr[mid+1+i];

    int i{}, j{}, k{start};

    while (i < n && j < m) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else if (right[j] < left[i]) arr[k++] = right[j++];
    }

    while (i < n) arr[k++] = left[i++];
    while (j < m) arr[k++] = right[j++];
}

void util(int arr[], int start, int end) {
    if (start < end) {
        int mid {start + (end - start) / 2};
        util(arr,start, mid);
        util(arr,mid+1, end);
        merge(arr, start, mid, end);
    }
}

// Using Merge sort
void sort012(int arr[], int n) {
    util(arr, 0, n-1);
}


int main () {
    int testCase {}, n {}, arr[500000] {};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i{}; i < n; i++) cin >> arr[i];
        sort012(arr, n);
        for (int i{}; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}
