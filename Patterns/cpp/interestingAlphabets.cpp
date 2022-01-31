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
    genericPrinter(1, currentRow, 'A' + n - currentRow, 1, true);
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
        char value{(char)('A' + n - row)};
        while(col <= row) {
            cout << value;
            value++;
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
