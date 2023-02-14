#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;


string addBinary(string a, string b) {
    string result;
    int carry {};
    int i {(int)a.size() - 1};
    int j {(int)b.size() - 1};
    while (i >= 0 || j >= 0) {
        int sum {carry};
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }
    if (carry == 1) {
        result = '1' + result;
    }
    return result;
}
