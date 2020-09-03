#include<bits/stdc++.h>
using namespace std;

void minLength(char* arr){
    int i{};
    int j = strlen(arr);
    int min{INT_MAX};
    int minStartIndex{};
    int cnt{};
    while(i<j){
        if(arr[i]==' '){
            if(cnt < min){
                min = cnt;
                minStartIndex = i-cnt;
            }
            cnt = 0;
            i++;
        }else{
            cnt++;
            i++;
        }
    }
    if(cnt<min){
        min = cnt;
        minStartIndex = i-cnt;
    }
    for(int i{minStartIndex};i<min+minStartIndex;i++){
        cout << arr[i];
    }cout << endl;
}

int main(){
    char* arr{new char[100000]};
    cin.get(arr,100000);
    minLength(arr);
}