#include<iostream>
#include<cstring>
#include<climits>
using std::cin;
using std::cout;
using std::endl;

int kadane(int* arr, int n) {
    int current_sum {}, best_sum{INT_MIN};
    for(int i{}; i < n; i++) {
        current_sum += arr[i];
        if(current_sum > best_sum) best_sum = current_sum;
        if(current_sum < 0) current_sum = 0;
    }
    return best_sum;
}

int maxSum(int** arr, int row, int col) {
    int sum{INT_MIN};
    for(int left{}; left < col; left++) {
        int* tmp{new int[row]};
        memset(tmp, 0, row * sizeof(int));
        for(int right{left}; right < col; right++) {
            for(int i{}; i < row; i++) tmp[i] += arr[i][right];
            int ans{kadane(tmp, row)};
            if(ans > sum) sum = ans;
        }
        delete [] tmp;
    }
    return sum;
}

int main() {
    int n,m;
    cin >> n >> m;
    int** grid {new int*[n]};
    for(int i{}; i < n; i++) {
        grid[i] = new int[m];
        for(int j{}; j < m; j++) cin >> grid[i][j];
    }

    int ans{maxSum(grid, n, m)};
    cout << ans << endl;

    for(int i{}; i < n; i++) delete [] grid[i];
    delete [] grid;
}
