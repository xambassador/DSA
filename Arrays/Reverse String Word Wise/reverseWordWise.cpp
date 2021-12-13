#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

void reverseString(char* arr, int i, int j) {
    while(i < j) {
        char a{arr[i]};
        arr[i] = arr[j];
        arr[j] = a;
        i++;
        j--;
    }
}


void reverseWordWise(char* arr){
    int i{},j{int(strlen(arr)) - 1};
    while(i < j) {
        char a{arr[i]};
        arr[i] = arr[j];
        arr[j] = a;
        i++;
        j--;
    }
    i = 0;
    j = strlen(arr);
    while(i < j) {
        int t{i};
        while(t < j) {
            if(arr[t] == ' ') break;
            t++;
        }
        reverseString(arr, i, t - 1);
        i = t + 1;
    }
}

int main() {
    char arr[1000];
    cin.get(arr,1000);
    reverseWordWise(arr);
    cout << arr << endl;
}
