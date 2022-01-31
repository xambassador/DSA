#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n) {
    // Base case
    if (currentRow == 0) return;

    // Call recursion.
    printPatternUtil(currentRow - 1, n);

    // My job on last row
    genericPrinter(1, currentRow, 'A' + currentRow - 1, 1, true);
    cout << endl;
}

// Recursive solution
void printPatternRec(int n) {
    printPatternUtil(n, n);
}

// Iterative solution
void printPattern(int n) {
    int row{1};
    while(row <= n) {
        int col{1};
        char value{(char)('A' + row - 1)};
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
