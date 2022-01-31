#include <iostream>
#include "Printer.h"
using std::cin;
using std::cout;
using std::endl;

void printPatternUtil(int currentRow, int n) {
    if (currentRow == 0) return;
    printPatternUtil(currentRow - 1, n);
    char value{'A'};
    genericPrinter(1, currentRow, value + currentRow - 1, 0, true);
    cout << endl;
}

// Recursive
void printPatternRec(int n) {
    printPatternUtil(n, n);
}

void printPattern(int n) {
    int row{1};
    char value{'A'};
    while(row <= n) {
        int col{1};
        while(col <= row) {
            cout << value;
            col++;
        }
        cout << endl;
        row++;
        value++;
    }
}

int main() {
    int n{};
    cin >> n;
    printPattern(n);
    cout << endl;
    printPatternRec(n);
}
