#include<bits/stdc++.h>
using namespace std;
 
void pairStarHelp(char* arr, int start, int end){
    //1. Base case if string is empty
    if(start > end){
        return;
    }
    //2. Call recursion
    pairStarHelp(arr,start+1,end);
    if(arr[start] == arr[start+1]){
        int i{end+1};
        while(i >= start+1){
            arr[i+1] = arr[i];
            i--;
        }
        arr[start+1] = '*';
        return;
    }
    return;
}

void pairStar(char* arr){
    pairStarHelp(arr,0,strlen(arr)-1);
}

int main(){ 
    char arr[100];
    cin >> arr;
    pairStar(arr);
    cout << arr << endl;
}