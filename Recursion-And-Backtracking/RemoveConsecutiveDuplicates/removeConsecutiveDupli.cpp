#include<bits/stdc++.h>
using namespace std;
 
void uniqueHelp(char* arr, int start, int end){
    // 1. Base case, if string is empty
    if(start>=end){
        return;
    }
    // 2. Call recursion
    uniqueHelp(arr,start+1,end);
    // 3. Our work is check start and start+1, if equal then remove it
    if(arr[start] == arr[start+1]){
        int i{start+1};
        while(i<end){
            arr[i] = arr[i+1];
            i++;
        }
        arr[i] = '\0';
        return;
    }
    return;
}

void unique(char* arr){
    uniqueHelp(arr,0,strlen(arr));
}

int main(){
    char* arr{new char[1000]};
    cin >> arr;
    unique(arr);
    cout << arr << endl;
    delete arr;
}