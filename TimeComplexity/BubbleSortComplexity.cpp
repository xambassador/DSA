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
void BubbleSort(int* arr, int n) {
    for (int i{}; i < n - 1; i++) {
        for (int j{}; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t {arr[j]};
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

// -----------------------------------------------------------------------------
int main() {
    cout << "Bubble Sort take time on n number of inputs : " << endl;
    cout << " Number of elements" << "\t\t" << "|" << "\t" << "Time (ms)" <<  "\t\t" << "|" << endl;
    for(int n{10}; n <= 1000000; n *= 10) {
        int* arr {new int[n]};
        long startTime, endTime;
        for (int i{}; i < n; i++) arr[i] = n-i;
        startTime = getTimeInMicroSeconds();
        BubbleSort(arr,n);
        endTime = getTimeInMicroSeconds();
        cout << "\t" << n << "\t\t\t" << "|" << "\t" << endTime - startTime << "\t\t\t" << "|" << endl;
    }
}
