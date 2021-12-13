#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void leaders(int arr[], int n) {
    int i{};
    while(i < n) {
        int j{i + 1};
        bool flag{false};
        while(j < n) {
            if(arr[i] > arr[j]) j++;
            else {
                flag = true;
                break;
            }
        }
        if(!flag) cout << arr[i] << " ";
        i++;
    }
}

int main() {
    int n, arr[1000000];
    cin >> n;
    for(int i{}; i < n; i++) cin >> arr[i];
    leaders(arr,n);
}
