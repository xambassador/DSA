#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    int s, d;
    cin >> s >> d;
    int arr[d];
    for(int i{}; i < d; i++) arr[i] = 0;
    arr[0] = 1;
    s = s - 1;
    int i{d - 1};
    while(i >=0) {
        if(i == 0) arr[i] += s;

        // if remaining sum is grater then 9
        if(s > 9) {
            arr[i] = 9;
            s -= 9;
        } else if(s <= 9) {
            arr[i] += s;
            s = 0;
        }
        i--;
    }
    for(int i{}; i < d; i++) cout << arr[i];
    cout << endl;
}
