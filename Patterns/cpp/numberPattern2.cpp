#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int totalRows) {
    // Base case: If n is zero, nothing needs to print
    if (currentRow == 0) return;

    // Call recursion. Recursion handle rows from 1 to totalRows - 1.
    printPatternUtil(currentRow - 1, totalRows);

    // My job on last row
    genericPrinter(1, totalRows - currentRow, ' ', 0, true);
    genericPrinter(1, currentRow, currentRow, 1);
    cout << endl;
}

// Recursive solution
void printPatternRec(int n) {
    // here printPatternUtil's first arg is currentRow. Current row
    // indicate from where to start or in which row I want to take decision.
    // So, here I take decision on last row. Rest of work will be handle by recursion.
    printPatternUtil(n,n);
}

// Iterative
void printPattern(int n) {
    int row{1};
    while(row <= n) {
        // first print spaces
        int space{1};
        while(space <= n - row) {
            cout << " ";
            space++;
        }
        // print columns
        int col{1}, value{row};
        while(col <= row) {
            cout << value << "";
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
