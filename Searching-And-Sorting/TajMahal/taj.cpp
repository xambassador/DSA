#include<iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i{}; i<n; i++) {
        cin >> arr[i];
    }
    int t[n];
    for(int i{}; i<n; i++) {
        if((arr[i]-i)%n == 0) t[i] = (arr[i]-i)/n;
        else if(arr[i] - i < 0) t[i] = 0;
        else t[i] = ((arr[i]-i)/n)+1;
    }

    for(int i{}; i<n; i++) cout << t[i] << " ";
    cout << endl;
    int min {INT_MAX};
    int min_index {-1};
    int ans[n];
    for(int i{}; i<n; i++) {
        ans[i] = i+t[i]*n;
        if(ans[i] < min) {
            min = ans[i];
            min_index = i;
        }
    }         
    cout << min_index+1 << endl;
}