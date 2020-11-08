#include<iostream>
using namespace std;
 
int turnOffFirstSetBit(int n){
    if(n == 0) return 0;

    int position = 0;
    int i = 0;
    while(i < 32) {
        int num = n & (1 << i);
        if(num == 0) {
            position++;
        }else {
            break;
        }
        i++;
    }
    n = n ^ (1<<position);
    return n;
}


int main() {
    int n;
    cin >> n;
    n = turnOffFirstSetBit(n);
    cout << n << endl;
}