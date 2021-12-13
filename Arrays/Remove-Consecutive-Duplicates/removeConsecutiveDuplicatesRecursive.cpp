#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

void unique(char* arr) {
    // Base case
    if(strlen(arr) == 0 || strlen(arr) == 1) return;
    unique(arr + 1);
    if(arr[0] == arr[1]) {
        int t{1};
        while(t < strlen(arr)) {
            arr[t-1] = arr[t];
            t++;
        }
        arr[t - 1] = arr[strlen(arr)];
        return;
    } else return;
}

int main() {
    char arr[100];
    cin >> arr;
    unique(arr);
    cout << arr << endl;
}
