#include<bits/stdc++.h>
using namespace std;
 
int stoi(char* arr, int start, int end){
    // 1. Base case, if string is empty
    if(start>end){
        return -1;
    }
    if(start == end){
        return arr[start]-'0';
    }
    return stoi(arr,start,end-1)*10+arr[end]-'0';
}

int stringToint(char* arr){
    return stoi(arr,0,strlen(arr)-1);
}

int main(){
    char arr[100];
    cin >> arr;
    cout << stringToint(arr) << endl;
}