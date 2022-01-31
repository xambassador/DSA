#pragma once
#include <iostream>
using std::cout;

void genericPrinter(int start, int end, int value, int increment = 0, bool isCharacter = false) {
    // Base case: If start cross end, then just return without doing anything
    if (start > end) return;
    // Check is isCharacter flag is set to true
    // if it is, then it indicate that value is character.
    // Now, First I do my job. My job is just chaeck value and according the type of value
    // print it and then delegate rest of the work to recursion.
    if (isCharacter) {
        char c{(char)value};
        cout << c;
    } else {
        cout << value;
    }
    // Call recursion for printing from start + 1 to end
    genericPrinter(start + 1, end, value + increment, increment, isCharacter);
}
