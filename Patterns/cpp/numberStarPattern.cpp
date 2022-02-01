#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n) {
    // Base case
    if (currentRow == 0) return;

    // Call Recursion
    printPatternUtil(currentRow - 1, n);

    // Decision on last row
    genericPrinter(1, n - currentRow + 1, 1, 1);
    genericPrinter(1, currentRow, '*', 0, true);
    genericPrinter(1, currentRow, '*', 0, true);
    genericPrinter(1, n - currentRow + 1, n - currentRow + 1, -1);
    cout << endl;
}

// Recursive solution
void printPatternRec(int n) {
    int col{1};
    while(col <= n) {
        cout << col;
        col++;
    }
    col = 1;
    int value{n};
    while(col <= n) {
        cout << value;
        col++;
        value--;
    }
    cout << endl;
    int row{1};
    n--;
    printPatternUtil(n, n);
}

// Iterative solution
void printPattern(int n) {
    int col{1};
    while(col <= n) {
        cout << col;
        col++;
    }
    col = 1;
    int value{n};
    while(col <= n) {
        cout << value;
        col++;
        value--;
    }
    cout << endl;
    int row{1};
    n--;
    while(row <= n) {
        // left triangle
        int col{1}, value{1};
        while(col <= n + 1 - row) {
            cout << value;
            value++;
            col++;
        }

        // left mid triangle
        col = 1;
        while(col <= row) {
            cout << "*";
            col++;
        }

        // right mid triangle
        col = 1;
        while(col <= row) {
            cout << "*";
            col++;
        }

        // right most triangle
        col = 1;
        value = n - row + 1;
        while(col <= n - row + 1) {
            cout << value;
            col++;
            value--;
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
