#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

// Recursive solution
void printPatternRec(int n) {
    // Base case: If n is zero then nothing is print
    if (n == 0) return;

    // I want to work on last row, So first i need to call recursion
    // The reason for this is if i do my job first then pattern print
    // in reverse order
    printPatternRec(n - 1);

    // At this point recursion print all rows from 1 to n - 1
    // Now it's my turn to print last row
    genericPrinter(1, n, n, 1);
    cout << endl;
}

// Iterative solution
void printPattern(int n) {
    int row{1};
    while(row <= n) {
        int col{1}, value{row};
        while(col <= row) {
            cout << value;
            value++;
            col++;
        }
        cout << endl;
        row++;
    }
}

int main() {
    int n{};
    cin >> n;
    printPattern(n);
    cout << endl;
    printPatternRec(n);
}
