#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(char* arr){
    int i{};
    // int j{strlen(arr)-1}; Narrowing conversion
    int j = strlen(arr)-1;
    while(i < j){
        if(arr[i] == arr[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    char arr[1000];
    cin >> arr; 
    cout << boolalpha << isPalindrome(arr) << endl;
}