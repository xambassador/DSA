#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int totalRows) {
    // Base case
    if (currentRow == 0) return;

    // Give work of printing rows from 1 to n - 1 to recursion
    printPatternUtil(currentRow - 1, totalRows);

    // My work on last row
    genericPrinter(1, totalRows, totalRows);
    cout << endl;
}

// Recursive solution
void printPatternRec(int totalRows) {
    printPatternUtil(totalRows, totalRows);
}


// Iterative solution
void printPattern(int n) {
    int row{1};
    while(row <= n) {
        int col{1};
        while(col <= n) {
            cout << n;
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
