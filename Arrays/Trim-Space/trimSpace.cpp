#include<bits/stdc++.h>
using namespace std;

void trimSpace(char* arr){
    int i{};
    int j = strlen(arr);
    while(i<j){
        if(arr[i] == ' '){
            int t{i+1};
            while(t<j){
                arr[t-1] = arr[t];
                t++;
            }
            arr[t-1] = arr[j];
            j--;
        }
        i++;
    }
}


int main(){
    char arr[100];
    cin.get(arr,100);
    trimSpace(arr);
    cout << arr << endl;
}