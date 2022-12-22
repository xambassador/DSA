#include<sys/time.h>
#include<iostream>
using std::swap;
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
int partition(int* p, int start, int end) {
    int key{p[end]}, i{start - 1};
    for (int j = start; j <= end - 1; j++) {
        if (p[j] <= key) {
            i++;
            swap(p[i], p[j]);
        }
    }
    swap(p[i + 1], p[end]);
    return i + 1;
}

// -----------------------------------------------------------------------------
void quickSort(int* p, int start, int end) {
    if (start < end) {
        int index{partition(p, start, end)};
        quickSort(p, start, index - 1);
        quickSort(p, index + 1, end);
    }
}

// -----------------------------------------------------------------------------
void sort(int* p, int n) {
    quickSort(p, 0, n - 1);
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
