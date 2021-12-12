#include<iostream>
#include<cstring>
using std::strlen;
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;

bool isPalindrome(char* arr, int startIndex, int endIndex) {
    // Base case: If there is only one Character or string is empty
    if(startIndex == endIndex || startIndex > endIndex) return true;

    // My calculation
    if(arr[startIndex] == arr[endIndex]) return isPalindrome(arr, startIndex + 1, endIndex - 1); // Recursive call
    else return false;
}

int main() {
    char arr[1000];
    cin >> arr;
    cout << boolalpha << isPalindrome(arr,0,strlen(arr) - 1) << endl;
}
