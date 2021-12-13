#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

void replaceCharacter(char* arr, char c1, char c2) {
    if(strlen(arr) == 0) return;
    if(arr[0] == c1) arr[0] = c2;
    replaceCharacter(arr+1,c1,c2);
}

int main() {
    char arr[100];
    cin >> arr;
    char c1,c2;
    cin >> c1 >> c2;
    replaceCharacter(arr,c1,c2);
    cout << arr << endl;
}
