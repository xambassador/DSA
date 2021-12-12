#include<iostream>
#include<cstring>
using std::strlen;
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

bool isPalindrome(char* arr) {
    int i{}, j{int(strlen(arr)) - 1};
    while(i < j) {
        if (arr[i] != arr[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    char arr[1000];
    cin >> arr;
    cout << boolalpha << isPalindrome(arr) << endl;
}
