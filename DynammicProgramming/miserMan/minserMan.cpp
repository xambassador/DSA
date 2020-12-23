#include<iostream>
#include<climits>

// Brute force approach
int minimum_fair(int** arr, int n, int m, int i, int j) {
    if (i == n) {
        return 0;
    }

    int option1 {minimum_fair(arr,n,m,i+1,j) + arr[i][j]};
    int option2 {INT_MAX};
    if (j+1 < m) {
        option2 = minimum_fair(arr,n,m,i+1,j+1) + arr[i][j];
    } 
    int option3 {INT_MAX};
    if (j-1 >= 0) {
        option3 = minimum_fair(arr,n,m,i+1,j-1) + arr[i][j];
    }
    int ans {std::min(option1, std::min(option2, option3))};
    return ans;
}

// Top down dp
int minimum_fair(int** arr, int n, int m, int i, int j, int** dp) {
    if (i == n) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int option1 {minimum_fair(arr,n,m,i+1,j,dp) + arr[i][j]};
    int option2 {INT_MAX};
    if (j+1 < m) {
        option2 = minimum_fair(arr,n,m,i+1,j+1, dp) + arr[i][j];
    } 
    int option3 {INT_MAX};
    if (j-1 >= 0) {
        option3 = minimum_fair(arr,n,m,i+1,j-1, dp) + arr[i][j];
    }
    dp[i][j] =  {std::min(option1, std::min(option2, option3))};
    return dp[i][j];
}



int main(){
    int n,m;
    std::cin >> n >> m;
    int** arr {new int*[n]};
    for(int i{}; i<n; i++) {
        arr[i] = new int[m];
        for (int j{}; j<m; j++) {
            std::cin >> arr[i][j];
        }
    }

    int minimum {INT_MAX};
    
    for (int bus{}; bus < m; bus++) {
        int** dp {new int*[n+1]};
        for(int i{}; i<n+1; i++) {
            dp[i] = new int[m+1];
            for (int j{}; j<m+1; j++) {
                dp[i][j] = -1;
            }
        } 
        // minimum = std::min(minimum_fair(arr,n,m,0,bus),minimum);
        minimum = std::min(minimum, minimum_fair(arr,n,m,0,bus,dp));
    }


    std::cout << minimum << std::endl;
}