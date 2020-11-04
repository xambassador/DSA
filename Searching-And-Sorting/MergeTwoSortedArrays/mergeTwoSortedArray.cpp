#include<bits/stdc++.h>
using namespace std;

int merge(int* arr1, int n1, int* arr2, int n2, int* output){
    int i{};
    int j{};
    int k{};
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            output[k++] = arr1[i++];
        }else{
            output[k++] = arr2[j++];
        }
    }
    while(i<n1){
        output[k++] = arr1[i++];
    }
    while(j<n2){
        output[k++] = arr2[j++];
    }
    return n1+n2;
}

int main(){
    int n1,n2;
    cin >> n1;
    int* arr1{new int[n1]};
    for(int i{};i<n1;i++){
        cin >> arr1[i];
    }
    cin >> n2;
    int* arr2{new int[n2]};
    for(int i{};i<n2;i++){
        cin >> arr2[i];
    }
    int* output{new int[1000000]};
    int ans = merge(arr1,n1,arr2,n2,output);
    for(int i{};i<ans;i++){
        cout << output[i] << " ";
    }cout << endl;
}