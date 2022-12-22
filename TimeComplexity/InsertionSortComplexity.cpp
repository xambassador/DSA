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
void InsertionSort(int* arr, int n) {
    for(int i{1}; i < n; i++) {
        int pickElement {arr[i]}, j{};
        for(j = i - 1; j >= 0 && arr[j] > pickElement; j--) arr[j + 1] = arr[j];
        arr[j + 1] = pickElement;
    }
}

// -----------------------------------------------------------------------------
int main() {
    cout << "Insertion Sort take time on n number of inputs : " << endl;
    cout << " Number of elements" << "\t\t" << "|" << "\t" << "Time (ms)" <<  "\t\t" << "|" << endl;
    for (int n{10}; n <= 1000000; n *= 10) {
        int* arr {new int[n]};
        long startTime, endTime;
        for (int i{}; i < n; i++) arr[i] = n - i;
        startTime = getTimeInMicroSeconds();
        InsertionSort(arr, n);
        endTime = getTimeInMicroSeconds();
        cout << "\t" << n << "\t\t\t" << "|" << "\t" << endTime - startTime << "\t\t\t" << "|" << endl;
    }
}
