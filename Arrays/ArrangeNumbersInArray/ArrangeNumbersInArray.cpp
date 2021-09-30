#include<bits/stdc++.h>
using namespace std;

void arrangeArray(int arr[], int n) {
    int start{}, end{n-1}, number{1};
    while (start <= end) {
        if (start == end) {
            arr[start] = number;
            start++;
            end--;
            continue;
        }
        arr[start++] = number++;
        arr[end--] = number++;
    }
}


int main(){
    int testCase{}, n{}, arr[10000]{};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        arrangeArray(arr,n);
    }
}