#include<sys/time.h>
#include<iostream>
using namespace std;


long getTimeInMicroSeconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void swap(int* p, int* q){
    int* t = p;
    p = q;
    q = t;
}

int partition(int* p, int start, int end){
    int key = p[end];
    int i = (start-1);
    for (int j = start; j <= end-1; j++){
        if (p[j] <= key){
            i++;
            swap(p[i],p[j]);
        }
    }
    swap(p[i+1],p[end]);
    return i+1;
}

void Quick_Sort(int* p, int start, int end){
    if (start < end){
        int index = partition(p,start,end);
        Quick_Sort(p,start,index-1);
        Quick_Sort(p,index+1,end);
    }
}

void Sort(int* p, int n){
    Quick_Sort(p,0,n-1);
}

int main(){
    cout << "Quick Sort take time on n number of inputs : " << endl;
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



