#include <iostream>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main() {
    int x;
    float y;
    cin >> x >> y;
    if ((x % 5 == 0) && (y - x - 0.5 >= 0)) y = y - x - 0.5;
    cout << fixed << setprecision(2) << y << endl;
}
