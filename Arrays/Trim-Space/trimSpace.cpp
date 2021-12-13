#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

void trimSpace(char* arr){
    int i{}, j{int(strlen(arr))};
    while(i < j) {
        if(arr[i] == ' ') {
            int t{i + 1};
            while(t < j) {
                arr[t-1] = arr[t];
                t++;
            }
            arr[t-1] = arr[j];
            j--;
        }
        i++;
    }
}

int main() {
    char arr[100];
    cin.get(arr,100);
    trimSpace(arr);
    cout << arr << endl;
}
