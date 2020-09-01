#include<bits/stdc++.h>
using namespace std;

void arrangeArray(int* arr, int size){
    int front{},back{size-1},i{1};
    while(front < back){
        arr[front] = i;
        i++;
        arr[back] = i;
        i++;
        front++;
        back--;
        if(front == back){
            arr[front] = i;
            break;
        }
    }   
} 


int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    arrangeArray(arr,n);
    for(int i{}; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}