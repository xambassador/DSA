#include<bits/stdc++.h>
using namespace std;

void unique(char* arr){
    int i{};
    int j = strlen(arr);
    while(i < j){
        if(arr[i] == arr[i+1]){
            int t{i+1};
            while(t < j){
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
    cin >> arr;
    unique(arr);
    cout << arr << endl;
}