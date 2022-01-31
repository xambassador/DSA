#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n) {
    // Base case
    if (currentRow == 0) return;

    // Calling Recursion. Recursion handle rows from 1 to n - 1
    printPatternUtil(currentRow - 1, n);

    // My job
    genericPrinter(1, currentRow, currentRow, -1);

    cout << endl;
}

// Recursive
void printPatternRec(int n) {
    printPatternUtil(n, n);
}

// Iterative
void printPattern(int n) {
    int row{1};
    while(row <= n) {
        int col{1}, value{row};
        while(col <=row) {
            cout << value;
            value--;
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
