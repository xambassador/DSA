#include<iostream>
using namespace std;

bool isSubsetSumMemoization(int* arr, int n, int k, int** dp) {
     if (k == 0) {
        return true;
    }

    if (n == 0) {
        return false;
    }

    if (dp[n][k] != -1) {
        return dp[n][k];
    }

    bool ans {};
    if (arr[0] <= k) {
        bool option1 {isSubsetSumMemoization(arr+1, n-1, k-arr[0],dp)};
        bool option2 {isSubsetSumMemoization(arr+1,n-1,k,dp)};
        ans = option1 || option2;
    } else {
        ans = isSubsetSumMemoization(arr+1, n-1, k,dp);
    }

    dp[n][k] = ans;
    return ans;
}


bool isSubsetPresent(int *arr, int n, int k)
{
    //Write your code here
    int** dp {new int*[n+1]};
    for(int i{}; i<n+1; i++) {
        dp[i] = new int[k+1];
        for(int j{}; j<k+1; j++) {
            dp[i][j] = -1;
        }
    }
    
    bool ans {isSubsetSumMemoization(arr,n,k,dp)};

	for(int i{}; i<n+1; i++) {
        delete [] dp[i];
    }
    delete [] dp;
    
    return ans;
}

int main() {
    int n;
    cin >> n;
    int* arr {new int[n]};
    for(int i{}; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    bool ans {isSubsetPresent(arr,n,k)};
    cout << boolalpha << ans << endl;
}