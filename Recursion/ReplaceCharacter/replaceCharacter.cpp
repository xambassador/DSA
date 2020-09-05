#include<bits/stdc++.h>
using namespace std;
 
void replaceChar(char* arr, char a, char x){
    // 1. Base case, if string is empty
    if(arr[0] == '\0'){
        return;
    }
    if(arr[0] == a){
        arr[0] = x;
    }
    replaceChar(arr+1,a,x);
}

int main(){
    char arr[100];
    cin >> arr;
    char a,x;
    cin >> a >> x;
    replaceChar(arr,a,x);
    cout << arr << endl;
}