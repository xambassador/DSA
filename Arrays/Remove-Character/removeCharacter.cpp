#include <iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

void removeCharacter(char* arr, char x) {
    int i{}, j{int(strlen(arr))};
    while(i < j) {
        if(arr[i] == x) {
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
    char x;
    cin >> x;
    removeCharacter(arr,x);
    cout << arr << endl;
}
