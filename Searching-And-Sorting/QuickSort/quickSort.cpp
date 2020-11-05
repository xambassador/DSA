#include<bits/stdc++.h>
using namespace std;
 
int partition(int* arr, int start, int end){
    int pivot {arr[start]};
    int cnt{0}; // This count is maintaine how many elements are smaller then arr[start], arr[start] is our pick element 
    for(int i{start+1}; i<=end; i++){
        if(arr[i] <= arr[start]){
            cnt++;
        }
    }
    int partitionIndex{start+cnt}; // This is our partiton index where the pick element is go
    // Now swap them
    int tmp{arr[start]};
    arr[start] = arr[partitionIndex];
    arr[partitionIndex] = tmp;
    
    //Now rearrange all elements,move all elements that are smaller then pick element on left side of partition index
    //Move all elements that are larger then pick element on right side of partition index
    int i{start},j{end};
    while(i<=partitionIndex && j>=partitionIndex){
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i<partitionIndex && j>partitionIndex) {
            int t {arr[i]};
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    return partitionIndex;
}

void quickSort(int* arr, int start, int end){
    if(start<end){
        int partitionIndex{partition(arr,start,end)};
        quickSort(arr,start,partitionIndex-1);
        quickSort(arr,partitionIndex+1,end);
    }
}

void Sort(int* arr, int n){
    quickSort(arr,0,n-1);
}

int main(){
    int n;
    cin >> n;
    int* arr{new int[n]};
    for(int i{};i<n;i++){
        cin >> arr[i];
    }
    Sort(arr,n);
    for(int i{};i<n;i++){
        cout << arr[i] << " ";
    }cout << endl;
}