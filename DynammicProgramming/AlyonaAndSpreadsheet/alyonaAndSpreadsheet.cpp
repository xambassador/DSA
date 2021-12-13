#include<iostream>
#include<climits>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;

int minElement(int* arr, int n) {
    int min{INT_MAX};
    for(int i{}; i < n; i++) {
        if(arr[i] < min) min = arr[i];
    }
    return min;
}

int main() {
    int row, col;
    cin >> row >> col;

    int* row1{new int[col]};
    int* row2{new int[col]};

    int* dp1{new int[col]};
    int* dp2{new int[col]};

    int* ans{new int[row]}; // in this array we store minimum row number

    for(int i{}; i < col; i++) cin >> row1[i];

    for(int i{}; i < col; i++) cin >> row2[i];

    for(int i{}; i < col; i++) dp1[i] = 0;

    for(int i{}; i < col; i++) {
        if(row2[i] >= row1[i]) dp2[i] = 0;
        else dp2[i] = 1;
    }

    ans[0] = minElement(dp1,col);
    ans[1] = minElement(dp2,col);


    for(int i{2}; i < row; i++) {
        for(int j{}; j < col; j++) dp1[j] = dp2[j];

        for(int j{}; j < col; j++) row1[j] = row2[j];

        for(int j{}; j < col; j++) cin >> row2[j];

        for(int j{}; j < col; j++) {
            if(row2[j] >= row1[j]) dp2[j] = dp1[j];
            else dp2[j] = i;
        }

        ans[i] = minElement(dp2,col);
    }

    int q;
    cin >> q;
    while(q--) {
        int li, ri;
        cin >> li >> ri;
        if(ans[ri-1] < li) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
