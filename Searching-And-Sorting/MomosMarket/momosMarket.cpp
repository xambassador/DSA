#include<iostream>
using namespace std;
 

int search(int* prefixSum, int start, int end, long long x) {
    if(start > end) {
        return end;
    }

    int mid {(start+end)/2};
    int midElement {prefixSum[mid]};

    if(midElement == x) return mid;

    if(x < midElement) {
        if(mid-1 >= start && x >= prefixSum[mid-1] && x < midElement) return mid-1;
        else return search(prefixSum, start, mid-1,x);
    }

    if(x > midElement) {
        if(mid+1 >= end && prefixSum[mid+1] >= x && x < midElement) return mid;
        else search(prefixSum, mid+1, end, x);
    }
} 


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i{0}; i<n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    
    for(int i{1}; i<n; i++) arr[i] = arr[i-1]+arr[i];
    cout << endl;

    while(q--) {
        long long x;
        cin >> x;
        int sAns {search(arr, 0, n-1, x)}; 
        int numOfMomos {sAns+1};
        long long remainingMoney {x - arr[sAns]};

        cout << numOfMomos << " " << remainingMoney << endl;
    }   
}