#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void printSubStr(char* arr) {
    for(int i{}; arr[i] != '\0'; i++) {
        for(int j{i}; arr[j] != '\0'; j++) {
            for(int z{i}; z <= j ; z++) cout << arr[z];
            cout << endl;
        }
    }
}

int main() {
    char arr[1000];
    cin >> arr;
    printSubStr(arr);
}
