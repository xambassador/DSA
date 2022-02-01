#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n, bool isUpperTriangle = true) {
    // Base case
    if (currentRow == 0) return;

    // Call recursion
    printPatternUtil(currentRow - 1, n, isUpperTriangle);

    // My job on last row
    // Here I have two traigles. So, I work on last rows of both triangle.
    // To decide on which triangle I am, isUpperTriangle flag is set according
    // to it.

    // Logic for printing upper triangle
    if (isUpperTriangle) {
        // space
        genericPrinter(1, n - currentRow, ' ', 0, true);
        // Mid triangle
        genericPrinter(1, currentRow, '*', 0, true);
        // last triangle
        genericPrinter(1, currentRow - 1, '*', 0, true);
        cout << endl;
    }
    // logic for printing lower triangle
    else {
        // space
        genericPrinter(1, currentRow, ' ', 0, true);
        // mid triangle
        genericPrinter(1, n + 1 - currentRow, '*', 0, true);
        // last triangle
        genericPrinter(1, n - currentRow, '*', 0, true);
        cout << endl;
    }
}

// Recursive solution
void printPatternRec(int n) {
    int upperTriangleRows{(n / 2) + 1};
    // Upper triangle
    printPatternUtil(upperTriangleRows, upperTriangleRows);
    // lower triangle
    int lowerTriangleRows{(n / 2)};
    printPatternUtil(lowerTriangleRows, lowerTriangleRows, false);
}

// Iterative solution
void printPattern(int n) {
    int upperTriangleRows{(n / 2) + 1};
    int lowerTriangleRows{(n / 2)};

    // Upper triangle
    int row{1};
    while(row <= upperTriangleRows) {
        int space{1};
        while(space <= upperTriangleRows - row) {
            cout << " ";
            space++;
        }

        // Mid triangle
        int col{1};
        while(col <= row) {
            cout << "*";
            col++;
        }

        // Last triangle
        col = 1;
        while(col <= row - 1) {
            cout << "*";
            col++;
        }
        cout << endl;
        row++;
    }

    // lower triangle
    row = 1;
    while(row <= lowerTriangleRows) {
        int space{1};
        while(space <= row) {
            cout << " ";
            space++;
        }
        // Mid triangle
        int col{1};
        while(col <= lowerTriangleRows + 1 - row) {
            cout << "*";
            col++;
        }
        // Last triangle
        col = 1;
        while(col <= lowerTriangleRows - row) {
            cout << "*";
            col++;
        }

        cout << endl;
        row++;
    }
}

int main() {
    int n{}; // n is always odd
    cin >> n;

    // Edge case, if user enter even number then return
    if (n % 2 == 0) return 0;

    printPattern(n);
    cout << endl;
    printPatternRec(n);
}
