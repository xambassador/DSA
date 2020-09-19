#include<sys/time.h>
#include<iostream>
using namespace std;


long getTimeInMicroSeconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void merge(int* arr, int start, int mid, int end){
    int n{(mid-start)+1};
    int m{end-mid};
    int l[n],r[n];
    for(int i{};i<n;i++){
        l[i] = arr[start+i];
    }
    for(int i{};i<m;i++){
        r[i] = arr[mid+1+i];
    }
    int i{},j{},k{start};
    while(i<n && j<m){
        if(l[i] < r[j]){
            arr[k++] = l[i++];
        }else{
            arr[k++] = r[j++];
        }
    }
    while(i<n){
        arr[k++] = l[i++];
    }
    while(j<m){
        arr[k++] = r[j++];
    }
}

void mergeSort(int* arr, int start, int end){
    if(start < end){
        int mid{start+(end-start)/2};
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

void Sort(int* arr, int n){
    mergeSort(arr,0,n-1);
}

int main(){
    cout << "Merge Sort take time on n number of inputs : " << endl;
    cout << " Number of elements" << "\t\t" << "|" << "\t" << "Time (ms)" <<  "\t\t" << "|" << endl;
    for(int n{10}; n<=1000000; n *= 10){
        int* arr{new int[n]};
        long startTime, endTime;
        for(int i{};i<n;i++){
            arr[i] = n-i;
        }
        startTime = getTimeInMicroSeconds();
        Sort(arr,n);
        endTime = getTimeInMicroSeconds();
        cout << "\t" << n << "\t\t\t" << "|" << "\t" << endTime - startTime << "\t\t\t" << "|" << endl;
    }
}
