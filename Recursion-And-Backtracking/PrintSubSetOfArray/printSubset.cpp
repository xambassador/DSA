#include<bits/stdc++.h>
using namespace std;
 
void printSubset(int* arr, int n, int* output, int nextIndex){
    if(n == 0){
        for(int i{};i<nextIndex;i++){
            cout << output[i] << " ";
        }cout << endl;
        return;
    }
    printSubset(arr+1,n-1,output,nextIndex);
    int narr[100];
    for(int i{};i<nextIndex;i++){
        narr[i] = output[i];
    }
    narr[nextIndex] = arr[0];
    printSubset(arr+1,n-1,narr,nextIndex+1);
}

int main(){
   int n;
   cin >> n;
   int* arr{new int[n]};
   for(int i{};i<n;i++){
       cin >> arr[i];
   }
   int* output{new int[n]};
   printSubset(arr,n,output,0);
   delete arr;
}