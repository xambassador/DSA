#include<bits/stdc++.h>
using namespace std;
 
void replacePIHelp(char* arr, int start, int end){
    // 1. Base case, if string is empty or string have only one character, then simply return
    if(start>=end){
        return;
    }
    // 2. Our part is, we check start index character and start+1 index character
    // If both are same as string 'pi' then we do shifting
    replacePIHelp(arr,start+1,end);
    if(arr[start] == 'p' && arr[start+1] == 'i'){
        int i{end};
        while(i >= start+2){
            arr[i+2] = arr[i];
            i--;
        }
        arr[start] = '3';
        arr[start+1] = '.';
        arr[start+2] = '1';
        arr[start+3] = '4';
    }
}

void replacePI(char* arr){
    replacePIHelp(arr,0,strlen(arr));
}

int main(){
    char* arr{new char[1000]};
    cin >> arr;
    replacePI(arr);
    cout << arr << endl;
    delete arr;
}