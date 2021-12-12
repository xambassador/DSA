#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int sum(int arr[], int size) {
    int ans{};
    for(int i{}; i < size; i++) ans += arr[i];
    return ans;
}

int main() {
    int size, arr[1000000];
    cin >> size;
    for(int i{}; i < size; i++) cin >> arr[i];
    cout << sum(arr,size) << endl;
}
