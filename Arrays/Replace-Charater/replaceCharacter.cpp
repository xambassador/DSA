#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
using std::strlen;

void replaceCharacter(char* arr, char c1, char c2) {
    int i{}, j{int(strlen(arr)) - 1};
    while(i < j) {
        if(arr[i] == c1) {
            arr[i] = c2;
            i++;
            if(arr[j] == c1) {
                arr[j] = c2;
                j--;
            }
        } else {
            i++;
            j--;
        }
    }
}

int main() {
    char arr[1000];
    cin >> arr;
    char c1,c2;
    cin >> c1 >> c2;
    replaceCharacter(arr,c1,c2);
    cout << arr << endl;
}
