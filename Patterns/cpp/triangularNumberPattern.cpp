#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n) {
    if (currentRow == 0) return;
    printPatternUtil(currentRow - 1, n);
    genericPrinter(1, currentRow, currentRow);
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
        while(col <= row) {
            cout << row;
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
