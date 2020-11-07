#include<iostream>
using namespace std;


void help(int* arr, int start, int end) {
    if(start > end) return;

    if(start == end) return;

    if(arr[start+1] == arr[start]-1) {
        int t{arr[start]};
        arr[start] = arr[start+1];
        arr[start+1] = t;
    }
    help(arr,start+1,end);
}


bool isPossible(int* arr, int n) {
    help(arr,0,n-1);
    for(int i{}, j{1}; j<n; i++, j++) {
        if(arr[i] > arr[j]) return false;
    }
    return true;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i{}; i<n; i++) {
            cin >> arr[i];
        }

        bool ans{isPossible(arr,n)};
        if(ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    } 
    
}