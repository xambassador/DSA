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
    genericPrinter(1, n - currentRow, ' ', 0, true);
    // Mid triangle
    genericPrinter(1, currentRow, currentRow, -1);
    // Last triangle
    genericPrinter(1, currentRow - 1, 2, 1);
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
        int space{1};
        while(space <= n - row) {
            cout << " ";
            space++;
        }
        int col{1}, value{row};
        while(col <= row) {
            cout << value;
            value--;
            col++;
        }
        col = 1;
        value = 2;
        while(col <= row - 1) {
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
