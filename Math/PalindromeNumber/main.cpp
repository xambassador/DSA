#include <iostream>

bool isPalindrome(int x) {
    if(x < 0 || (x % 10 == 0 && x != 0)) return false;
    int reverseHalfNum {};
    while(x > reverseHalfNum) {
        reverseHalfNum = reverseHalfNum * 10 + x % 10;
        x /= 10;
    }
    return x == reverseHalfNum || x == reverseHalfNum / 10;
}
