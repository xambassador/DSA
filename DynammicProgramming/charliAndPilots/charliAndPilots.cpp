#include<iostream>
#include<climits>



int minSalary(int* captain, int* assistant, int n, int X) {
    if (n == 0) {
        return 0;
    }

    // if x is 0, that means either we create pairs of assistant and captain for current n or we start from begining
    int ans{};
    if (X == 0) {
        // x is 0, then current pilot is consider as younger, so he can't become captain, but he can become assistant
        ans = minSalary(captain+1, assistant+1, n-1, X+1) + assistant[0];
    } else if (X == n) {
        ans = minSalary(captain+1, assistant+1, n-1,X-1) + captain[0];
    } else {
        int option1 = minSalary(captain+1,assistant+1,n-1,X+1) + assistant[0];
        int option2 = minSalary(captain+1, assistant+1,n-1,X-1) + captain[0];
        ans = std::min(option1,option2);
    }
    return ans;
}


int minSalary(int* captain, int* assistant, int n, int X, int** dp) {
    if (n == 0) {
        return 0;
    }

    if(dp[n][X] != -1) {
        return dp[n][X];
    }

    // if x is 0, that means either we create pairs of assistant and captain for current n or we start from begining
    int ans{};
    if (X == 0) {
        // x is 0, then current pilot is consider as younger, so he can't become captain, but he can become assistant
        ans = minSalary(captain+1, assistant+1, n-1, X+1,dp) + assistant[0];
    } else if (X == n) {
        ans = minSalary(captain+1, assistant+1, n-1,X-1,dp) + captain[0];
    } else {
        int option1 = minSalary(captain+1,assistant+1,n-1,X+1,dp) + assistant[0];
        int option2 = minSalary(captain+1, assistant+1,n-1,X-1,dp) + captain[0];
        ans = std::min(option1,option2);
    }
    dp[n][X] = ans;
    return ans;
}



int main(){
    int n;
    std::cin >> n;
    int captain[n],assistant[n];
    for (int i{}; i<n; i++) {
        int x,y;
        std::cin >> x >> y;
        captain[i] = x;
        assistant[i] = y;
    }

    int ans {minSalary(captain,assistant,n,0)};
    std::cout << ans << std::endl;

    int** dp {new int*[n+1]};
    for(int i{}; i<n+1; i++) {
        dp[i] = new int[n];
        for(int j{}; j<n; j++) {
            dp[i][j] = -1;
        }
    }

    ans = minSalary(captain,assistant,n,0,dp);
    std::cout << ans << std::endl;
}