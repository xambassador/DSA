#include<iostream>
using namespace std;
 

long long merge(long long* arr, int start, int mid, int end) {
    int n = (mid-start) + 1;
    int m = (end - (mid+1)) + 1;
    int len = m;
    long long L[n], R[m];
    for(int i=0; i<n; i++) {
        L[i] = arr[i+start];
    }
    for(int i=0; i<m; i++) {
        R[i] = arr[i+mid+1];
    }

    int i = 0, j = 0, k = start;
    long long ans = 0;
    while(i < n && j < m) {
        if(L[i] < R[j]) {
            ans += len * L[i];
            arr[k++] = L[i++];
        }else {
            arr[k++] = R[j++];
            len--;
        }
    }

    while(i < n) {
        arr[k++] = L[i++];
    }
    while(j < m) {
        arr[k++] = R[j++];
    }

    return ans;
}


long long merge_sort(long long* arr, int start, int end) {
    long long ans = 0;
    if(start < end) {
        int mid = (start+end)/2;
        long long left = merge_sort(arr,start,mid);
        long long right = merge_sort(arr,mid+1,end);
        long long myAns = merge(arr,start,mid,end);   
        return left + right + myAns;     
    }
    return ans;
}


long long solve(long long* arr, int n) {
    long long ans =  merge_sort(arr,0,n-1);
    return ans;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long arr[n];
        for(int i{0}; i<n; i++) {
            cin >> arr[i];
        }

        long long ans {solve(arr,n)};
        cout << ans << endl;
    }
}