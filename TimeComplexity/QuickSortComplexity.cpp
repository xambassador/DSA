#include<sys/time.h>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

long getTimeInMicroSeconds() {
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

// -----------------------------------------------------------------------------
int partition(int* arr, int start, int end) {
    int cnt{0}; // This count is maintaine how many elements are smaller then arr[start], arr[start] is our pick element
    for(int i{start}; i <= end; i++) {
        if(arr[i] < arr[start]) cnt++;
    }
    int partitionIndex{start + cnt}; // This is our partiton index where the pick element is go
    // Now swap them
    int tmp{arr[start]};
    arr[start] = arr[partitionIndex];
    arr[partitionIndex] = tmp;

    //Now rearrange all elements,move all elements that are smaller then pick element on left side of partition index
    //Move all elements that are larger then pick element on right side of partition index
    int i{start}, j{end};
    while (i < partitionIndex && j > partitionIndex) {
        if (arr[i] > arr[partitionIndex]) {
            if (arr[j] < arr[partitionIndex]) {
                int t{arr[j]};
                arr[j] =  arr[i];
                arr[i] = t;
                i++;
                j--;
            } else {
                j--;
            }
        } else {
            i++;
        }
    }
    return partitionIndex;
}

// -----------------------------------------------------------------------------
void quickSort(int* arr, int start, int end) {
    if(start < end) {
        int partitionIndex{partition(arr, start, end)};
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr,partitionIndex + 1, end);
    }
}

// -----------------------------------------------------------------------------
void sort(int* arr, int n) {
    quickSort(arr, 0,n - 1);
}

// -----------------------------------------------------------------------------
int main() {
    cout << "Quick Sort take time on n number of inputs : " << endl;
    cout << " Number of elements" << "\t\t" << "|" << "\t" << "Time (ms)" <<  "\t\t" << "|" << endl;
    for (int n{10}; n <= 1000000; n *= 10) {
        int* arr{new int[n]};
        long startTime, endTime;
        for (int i{}; i < n; i++) arr[i] = n - i;
        startTime = getTimeInMicroSeconds();
        sort(arr, n);
        endTime = getTimeInMicroSeconds();
        cout << "\t" << n << "\t\t\t" << "|" << "\t" << endTime - startTime << "\t\t\t" << "|" << endl;
    }
}
