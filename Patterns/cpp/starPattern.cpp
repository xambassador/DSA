#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int totalRows) {
    // Base case : If currentRow is zero
    if (currentRow == 0) return;

    // Call recursion
    printPatternUtil(currentRow - 1, totalRows);

    // My job
    // print spaces
    genericPrinter(1, totalRows - currentRow, ' ', 0, true);
    // print mid triangle
    genericPrinter(1, currentRow, '*', 0, true);
    // print last triangle
    genericPrinter(1, currentRow - 1, '*', 0, true);

    cout << endl;
}

// Recursive solution
void printPatternRec(int n) {
    printPatternUtil(n, n);
}

void printPattern(int n) {
    int row{1};
    while(row <= n) {
        // print spaces
        int space{1};
        while(space <= n - row) {
            cout << " ";
            space++;
        }

        // mid triangle
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

        // press enter
        cout << endl;
        row++;
    }
}

int main() {
    int n{};
    cin >> n;
    printPattern(n);
    printPatternRec(n);
}
