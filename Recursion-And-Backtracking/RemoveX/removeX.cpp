#include<bits/stdc++.h>
using namespace std;
 
void removeX(char* arr){
    // 1. Base case, if string is empty
    if(arr[0]=='\0'){
        return;
    }
    removeX(arr+1);
    //2. Our part is check first character is 'x' or not
    if(arr[0] == 'x'){
        int i{1};
        while(arr[i] != '\0'){
            arr[i-1] = arr[i];
            i++;
        }
        arr[i-1] = '\0';
    }
}

int main(){
    char* arr{new char[1000]};
    cin >> arr;
    removeX(arr);
    cout << arr << endl;
    delete arr;
}