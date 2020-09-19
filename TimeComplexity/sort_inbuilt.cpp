#include<sys/time.h>
#include<iostream>
#include<algorithm>
using namespace std;


long getTimeInMicroSeconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

int main(){
    cout << "Sort take time on n number of inputs : " << endl;
    cout << " Number of elements" << "\t\t" << "|" << "\t" << "Time (ms)" <<  "\t\t" << "|" << endl;
    for(int n{10}; n<=1000000; n *= 10){
        int* arr{new int[n]};
        long startTime, endTime;
        for(int i{};i<n;i++){
            arr[i] = n-i;
        }
        startTime = getTimeInMicroSeconds();
        sort(arr,arr+n);
        endTime = getTimeInMicroSeconds();
        cout << "\t" << n << "\t\t\t" << "|" << "\t" << endTime - startTime << "\t\t\t" << "|" << endl;
    }
}
