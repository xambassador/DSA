#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n) {
    // Base case
    if (currentRow == 0) return;

    // Call recursion
    printPatternUtil(currentRow - 1, n);

    // My job on last row
    // print space
    genericPrinter(1, n - currentRow, ' ', 0, true);
    // Mid triangle
    genericPrinter(1, currentRow, '*', 0, true);
    // Last triangle
    genericPrinter(1, currentRow - 1, '*', 0, true);
    cout << endl;
}

// Recursive solution
void printPatternRec(int n) {
    printPatternUtil(n,n);
}

// Iterative
void printPattern(int n) {
    int row{1};
    while(row <= n) {
        int space{1};
        while(space <= n - row) {
            cout << " ";
            space++;
        }
        // Mid traingle
        int col{1};
        while(col <= row) {
            cout << "*";
            col++;
        }
        // last triangle
        col = 1;
        while(col <= row - 1) {
            cout << "*";
            col++;
        }
        row++;
        cout << endl;
    }
}

int main() {
    int n{};
    cin >> n;
    printPattern(n);
    cout << endl;
    printPatternRec(n);
}
