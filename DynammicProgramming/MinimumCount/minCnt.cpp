#include<iostream>
using namespace std;
 
bool isPerfecrSqre(int n) {
    for(int i{1}; i<=32; i++) {
        if(i*i == n) {
            return true;
        }
    }
    return false;
}


int help(int n) {
    // is given number is perfect square
    if(isPerfecrSqre(n)) {
        return 1;
    }

    if(n <= 3) {
        return n;
    }

    int count {n};
    for(int i{1}; i<n; i++ ) {
        if(i*i > n) {
            break;
        }
        count = min(count, help(n-(i*i))+1);
    }
    return count;
}


int minCount(int n) {
    return help(n);
}

int main() {
    int n;
    cin >> n;
    int ans {minCount(n)};
    cout << ans << endl;
}