#include<bits/stdc++.h>
using namespace std;


// Complexity O(n*m)
void intersectionOfArray(int* arr1, int n, int* arr2, int m){
    int i{},j{};
    while(i<n){
        while(j<m){
            if(arr1[i] == arr2[j]){
                cout << arr1[i] << endl;
                arr2[j] = INT_MIN;
                break;
            }
            j++;
        }
        j = 0;
        i++;
    }
} 

int main(){
    int n,m;
    cin >> n;
    int* arr1{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr1[i];
    }
    cin >> m;
    int* arr2{new int[m]};
    for(int i{};i<m;i++){
        cin >> arr2[i];
    }
    intersectionOfArray(arr1,n,arr2,m);
}