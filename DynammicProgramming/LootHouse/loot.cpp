#include<iostream>
#include<cstring>
using namespace std;
 

int dp[100000];

int help(int* arr, int n, int start) {
    if(start > n) {
        return 0;
    }

    if(start == n) {
        dp[start] = arr[start];
        return arr[start]; 
    }

    if(dp[start] > 0) {
        return dp[start];
    }

    int myAns{};
    int LootCurrentHouse {arr[start] + help(arr,n,start+2)};
    int NotLootCurrentHouse {help(arr,n,start+1)};
    myAns = max(LootCurrentHouse, NotLootCurrentHouse);
    dp[start] = myAns;
    return myAns;
} 


int maxMoneyLooted(int *arr, int n) {
    memset(dp,0,n*sizeof(int));
    return help(arr,n-1,0);
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0 ;i<n; i++) {
        cin >> arr[i];
    }
    cout << maxMoneyLooted(arr,n) << endl;
}