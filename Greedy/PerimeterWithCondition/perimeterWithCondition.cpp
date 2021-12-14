#include<iostream>
#include<algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;

int main() {
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{}; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int start{n - 3}, mid{n - 2}, end{n - 1};
    while(start + mid <= end) {
        start--;
        mid--;
        end--;
        if(start < 0) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << arr[start] << " " << arr[mid] << " " << arr[end] << endl;
}
