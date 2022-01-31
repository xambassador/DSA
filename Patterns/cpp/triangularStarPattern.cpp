#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n) {
    // Base case
    if (currentRow == 0) return;

    // Give work to recursion for row 1 to n - 1
    printPatternUtil(currentRow - 1, n);

    // My job
    genericPrinter(1, currentRow, '*', 0, true);

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
