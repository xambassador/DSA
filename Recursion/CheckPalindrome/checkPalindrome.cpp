#include<bits/stdc++.h>
using namespace std;
 
bool checkPalindromeHelp(char* arr, int start, int end){
    //1. Base case, if string is empty, return true
    if(start>end){
        return true;
    }
    //2. Our part is chaeck first and last character if both match give start+1 and end-1 string to
    //recursion and return recursion answer
    if(arr[start] == arr[end]){
        return checkPalindromeHelp(arr,start+1,end-1);
    }
    //If first and last not match
    return false;
}

bool checkPalindrome(char* arr){
    return checkPalindromeHelp(arr,0,strlen(arr)-1);
}

int main(){
    char* arr{new char[1000]};
    cin >> arr;
    cout << boolalpha << checkPalindrome(arr) << endl;
}