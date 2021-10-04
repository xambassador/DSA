#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void merge(int arr[], int start, int mid, int end) {
    int n {(mid - start)+1}, m {end - mid}, arr1[n], arr2[m];

    for (int i{} ; i<n ; i++) arr1[i] = arr[start + i];
    for (int i{}; i<m; i++) arr2[i] = arr[mid+1+i];

    int i{}, j{}, k{start};

    while(i < n && j < m) {
        if (arr1[i] != 0) {
            arr[k++] = arr1[i++];
        } else if (arr2[j] != 0) {
            arr[k++] = arr2[j++];
        } else {
            arr[k++] = arr1[i++];
            arr[k++] = arr2[j++];
        }
    }

    while(i < n) arr[k++] = arr1[i++];
    while(j < m) arr[k++] = arr2[j++];

}

void util(int arr[], int start, int end) {
    if (start < end) {
        int mid {start + (end - start) / 2};
        util(arr, start, mid);
        util(arr,mid+1, end);
        merge(arr, start, mid, end);
    }
}

// Approach - 2 : Using Merge sort
void pushZeroToEnd_1(int arr[], int n) {
    util(arr, 0, n-1);
}

// Approach - 1
void pushZeroToEnd(int* arr, int n){
    int i{};
    int j{1};
    while(j<n){
        if(arr[i] == 0){
            if(arr[j] == 0){
                j++;
            }else{
                int t{arr[i]};
                arr[i] = arr[j];
                arr[j] = t;
            }
        }else{
            i++;
            j++;
        }
    }
}

int main(){
    int n{}, testCase{}, arr[1000000]{};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i{}; i<n; i++) cin >> arr[i];
        // pushZeroToEnd(arr,n);
        pushZeroToEnd_1(arr,n);
    }
    
}