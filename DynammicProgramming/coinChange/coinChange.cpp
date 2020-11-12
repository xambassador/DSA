#include<iostream>
using namespace std;


int dp[10000][100];

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	if(value == 0) {
        return 1;
    }
    if(value < 0) {
        return 0;
    }
    if(numDenominations == 0) {
        return 0;
    }

    if(dp[value][numDenominations] > -1) {
        return dp[value][numDenominations]; 
    }

    int first = countWaysToMakeChange(denominations,numDenominations, value - denominations[0]);
    int second = countWaysToMakeChange(denominations+1, numDenominations-1,value);
    dp[value][numDenominations] = first+second;
    return first+second;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i{}; i<n; i++) {
        cin >> arr[i];
    }
    int val;
    cin >> val;
    for(int i{}; i<=val; i++) {
        for(int j{};j<=n; j++) {
            dp[i][j] = -1;
        }
    }
    int ans {countWaysToMakeChange(arr,n,val)};
    cout << ans << endl;
}