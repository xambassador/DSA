#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
 

int calCost(int* arr, int n, int k, int l, int pivot) {
    int increment = 0;
    int decrement = 0;
    for(int i = 0; i<n; i++) {
        if(arr[i] < pivot) {
            increment += pivot - arr[i];
        }

        if(arr[i] > pivot) {
            decrement += arr[i] - pivot;
        }
    }

    if(increment < decrement) {
        return INT_MAX;
    }

    return (decrement*k) + ((increment-decrement)*l);
}


int main() {
    int n,k,l;
    cin >> n >> k >> l;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int cost = INT_MAX;

    for(int i =0; i<n; i++) {
        if(arr[i] < minimum) {
            minimum = arr[i];
        }

        if(arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    
    for(int i=minimum; i<=maximum; i++) {
        cost = min(cost, calCost(arr,n,k,l,i));
    }
    cout << cost << endl;
}