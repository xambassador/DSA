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
    // print spaces
    genericPrinter(1, n - currentRow, ' ', 0, true);
    // print values
    genericPrinter(1, currentRow, 1, 1);
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
        int space{1};
        while(space <= n - row) {
            cout << " ";
            space++;
        }

        int col{1}, value{1};
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
