#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "1" << endl;
    int i = 1;
    while(i < n) {
        int col = 1;
        cout << i; 
        while(col <= i-1) {
            cout << "0";
            col++;
        }
        cout << i << endl;
        i++;
    }
}