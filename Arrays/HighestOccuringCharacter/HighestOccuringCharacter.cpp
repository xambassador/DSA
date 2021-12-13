#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;
using std::sort;

char highestOccur(char* arr) {
    sort(arr, arr + strlen(arr));
    char frequancyArr[128]{};
    int i{}, j{int(strlen(arr))};
    while(i < j) {
        frequancyArr[arr[i]]++;
        i++;
    }
    int max{INT_MIN}, maxIndex{};
    i = 0;
    while(i < 128) {
        if(frequancyArr[i] > max) {
            max = frequancyArr[i];
            maxIndex = i;
        }
        i++;
    }
    return maxIndex;
}

int main() {
    char arr[100];
    cin >> arr;
    cout << highestOccur(arr) << endl;
}
