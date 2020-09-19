#include<sys/time.h>
#include<iostream>
using namespace std;


long getTimeInMicroSeconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void SelSort(int* arr, int n){
    for(int i{};i<n;i++){
        int min{arr[i]};
        int minIndex{i};
        for(int j{i+1};j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minIndex = j;
            }
        }
        int t{arr[i]};
        arr[i] = arr[minIndex];
        arr[minIndex] = t;
    }
}

int main(){
    cout << "Selection Sort take time on n number of inputs : " << endl;
    cout << " Number of elements" << "\t\t" << "|" << "\t" << "Time (ms)" <<  "\t\t" << "|" << endl;
    for(int n{10}; n<=1000000; n *= 10){
        int* arr{new int[n]};
        long startTime, endTime;
        for(int i{};i<n;i++){
            arr[i] = n-i;
        }
        startTime = getTimeInMicroSeconds();
        SelSort(arr,n);
        endTime = getTimeInMicroSeconds();
        cout << "\t" << n << "\t\t\t" << "|" << "\t" << endTime - startTime << "\t\t\t" << "|" << endl;
    }
}
