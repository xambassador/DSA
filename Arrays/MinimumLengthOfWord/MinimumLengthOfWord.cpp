#include<iostream>
#include<cstring>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

void minLength(char* arr) {
    int i{}, j{int(strlen(arr))}, min{INT_MAX}, minStartIndex{}, cnt{};
    while(i < j) {
        if(arr[i] == ' ') {
            if(cnt < min) {
                min = cnt;
                minStartIndex = i-cnt;
            }
            cnt = 0;
            i++;
        } else {
            cnt++;
            i++;
        }
    }
    if(cnt < min) {
        min = cnt;
        minStartIndex = i - cnt;
    }
    for(int i{minStartIndex}; i < min + minStartIndex; i++) cout << arr[i];
    cout << endl;
}

int main() {
    char* arr{new char[100000]};
    cin.get(arr, 100000);
    minLength(arr);
    delete [] arr;
}
