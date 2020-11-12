#include<iostream>
using namespace std;
 

int* lis(int* arr, int n) {
    int* output {new int[n]};
    output[0] = 1;
    for(int i{1}; i<n; i++) {
        int tmp {0};
        for(int j{0}; j<i; j++) {
            if(arr[i] > arr[j]) {
                tmp = max(tmp, output[j]);
            }
        }
        output[i] = tmp+1;
    }
    return output;
}

int* lisBack(int* arr, int n) {
    int* output {new int[n]};
    output[n-1] = 1;
    for(int i{n-2}; i>=0; i--) {
        int tmp {0};
        for(int j{i+1}; j<n; j++) {
            if(arr[i] > arr[j]) {
                tmp = max(tmp, output[j]);
            }
        }
        output[i] = tmp+1;
    }
    return output;
}


int longestBitonicSubarray(int *arr, int n) {
    int* LISfront {lis(arr,n)};
    int* LISback {lisBack(arr,n)};

    int maxLen {0};
    for(int i{}; i<n; i++) {
        if(LISfront[i] + LISback[i] - 1 > maxLen) {
            maxLen = LISfront[i] + LISback[i] - 1;
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i{}; i<n;i++) {
        cin >> arr[i];
    }
    cout << longestBitonicSubarray(arr,n) << endl;
}