#include<bits/stdc++.h>
using namespace std;

// O(nlogn)
int uniqueElement(int* arr, int size){
    sort(arr,arr+size);
    int i{},ans{};
    while(i<size){
        if(arr[i] != arr[i+1]){
            ans = arr[i];
            break;
        }
        i++;
    }
    return ans;
}

// O(n^2)
int findeUnique_1(int arr[], int size) {
    for (int i{}; i<size; i++) {
        bool isCurrentElementFound {false};

        for (int j{}; j<size; j++) {
            if (i == j) continue;
            if (arr[i] == arr[j]) {
                isCurrentElementFound = true;
                break;
            }
        }

        if (!isCurrentElementFound) return arr[i];
    }

    return -1;
}


int main(){
    int testCase{}, n{}, arr[1000]{};
    cin >> testCase;

    while (testCase--) {
        cin >> n;
        for (int i{}; i<n; i++) cin >> arr[i];
        int ans {findeUnique_1(arr, n)};
        cout << ans << endl;
    }
}