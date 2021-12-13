#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int squareBrackets(int openingBrackets, int closingBrackets, int totalBrackets, bool* arr) {
    if (openingBrackets > totalBrackets || closingBrackets > totalBrackets) return 0;
    if (openingBrackets == totalBrackets && closingBrackets == totalBrackets) return 1;
    int ans {};
    if (openingBrackets == closingBrackets || arr[openingBrackets + closingBrackets + 1]) ans = squareBrackets(openingBrackets + 1, closingBrackets, totalBrackets, arr);
    else if (openingBrackets == totalBrackets) ans = squareBrackets(openingBrackets, closingBrackets + 1, totalBrackets, arr);
    else {
        int ans1{squareBrackets(openingBrackets + 1, closingBrackets, totalBrackets, arr)};
        int ans2{squareBrackets(openingBrackets, closingBrackets + 1, totalBrackets, arr)};
        ans = ans1 + ans2;
    }
    return ans;
}

int squareBrackets(int openingBrackets, int closingBrackets, int totalBrackets, bool* arr, int dp[21][21]) {
    if (openingBrackets > totalBrackets || closingBrackets > totalBrackets) return 0;
    if (dp[openingBrackets][closingBrackets] != -1) return dp[openingBrackets][closingBrackets];
    if (openingBrackets == totalBrackets && closingBrackets == totalBrackets) return 1;

    int ans {};
    if (openingBrackets == closingBrackets || arr[openingBrackets + closingBrackets + 1]) ans = squareBrackets(openingBrackets + 1, closingBrackets, totalBrackets, arr, dp);
    else if (openingBrackets == totalBrackets) ans = squareBrackets(openingBrackets, closingBrackets + 1, totalBrackets, arr, dp);
    else {
        int ans1{squareBrackets(openingBrackets + 1, closingBrackets, totalBrackets, arr, dp)};
        int ans2{squareBrackets(openingBrackets, closingBrackets + 1, totalBrackets, arr, dp)};
        ans = ans1 + ans2;
    }
    dp[openingBrackets][closingBrackets] = ans;
    return ans;
}

int main(){
    int d;
    cin >> d;
    while(d--) {
        int n, k;
        cin >> n >> k;
        bool arr[(2 * n) + 1];
        for(int i{}; i<(2 * n) + 1; i++) arr[i] = false;
        for(int i{}; i < k; i++){
            int x;
            cin >> x;
            arr[x] = true;
        }
        int dp[21][21];
        for(int i{}; i < 21; i++) {
            for(int j{}; j < 21; j++) dp[i][j] = -1;
        }
        int ans{squareBrackets(0, 0, n, arr, dp)};
        cout << ans << endl;
    }
}
