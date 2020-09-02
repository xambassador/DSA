#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(char* arr, int startIndex, int endIndex){
    // Base case
    if(startIndex == endIndex){
        return true;
    }
    // Edge case if string is empty
    if(startIndex > endIndex){
        return false;
    }
    // My calculation
    if(arr[startIndex] == arr[endIndex]){
        return isPalindrome(arr,startIndex+1,endIndex-1); // Recursive call
    }else{
        return false;
    }
}

int main(){
    char arr[1000];
    cin >> arr;
    cout << boolalpha << isPalindrome(arr,0,strlen(arr)-1) << endl;
}