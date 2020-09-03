#include <bits/stdc++.h>
using namespace std;

void removeCharacter(char* arr, char x){
    int i{};
    int j = strlen(arr);
    while(i < j){
        if(arr[i] == x){
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
    cin.get(arr,100);
    char x;
    cin >> x;
    removeCharacter(arr,x);
    cout << arr << endl;
}