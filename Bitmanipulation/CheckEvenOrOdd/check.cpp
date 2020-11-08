#include<iostream>
using namespace std;
 
void check(int n) {
    if((n & (1 << 0)) == 0) {
        cout << "even" << endl;
    }else {
        cout << "Odd" << endl;
    }
}


int main() {
    int n;
    cin >> n;
    check(n);
}