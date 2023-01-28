#include <string>
#include <unordered_map>
#include <utility>
using std::string;
using std::unordered_map;
using std::make_pair;

int romanToInt(string s) {
    // Result is the final value
    int result {};
    // previous value
    int prev {};
    for (auto it {s.rbegin()}; it != s.rend(); ++it) {
        int current {};
        // Convert the character to its value
        switch (*it) {
            case 'I':
                current = 1;
                break;
            case 'V':
                current = 5;
                break;
            case 'X':
                current = 10;
                break;
            case 'L':
                current = 50;
                break;
            case 'C':
                current = 100;
                break;
            case 'D':
                current = 500;
                break;
            case 'M':
                current = 1000;
                break;
        }
        // If the current value is less than the previous value, then we need to subtract the current value from the result
        // Example: IV = 5 - 1 = 4
        if (current < prev) {
            result -= current;
        } else {
            // Otherwise, we add the current value to the result
            // Example: VI = 5 + 1 = 6
            result += current;
        }
        // Update the previous value
        prev = current;
    }
    return result;
}

// Roman to Integer using a map
int romanToInt_map(string s) {
    // Result is the final value
    int result {};
    // previous value
    int prev {};
    // Create a map of the roman numerals
    unordered_map<char, int> romanMap {
        make_pair('I', 1),
        make_pair('V', 5),
        make_pair('X', 10),
        make_pair('L', 50),
        make_pair('C', 100),
        make_pair('D', 500),
        make_pair('M', 1000)
    };
    for (auto it {s.rbegin()}; it != s.rend(); ++it) {
        int current {romanMap[*it]};
        // If the current value is less than the previous value, then we need to subtract the current value from the result
        // Example: IV = 5 - 1 = 4
        if (current < prev) {
            result -= current;
        } else {
            // Otherwise, we add the current value to the result
            // Example: VI = 5 + 1 = 6
            result += current;
        }
        // Update the previous value
        prev = current;
    }
    return result;
}

int romanToInt_map1(string s) {
    unordered_map<char, int> map;
    map.insert(make_pair('I', 1));
    map.insert(make_pair('V', 5));
    map.insert(make_pair('X', 10));
    map.insert(make_pair('L', 50));
    map.insert(make_pair('C', 100));
    map.insert(make_pair('D', 500));
    map.insert(make_pair('M', 1000));

    int decimal {};
    for(int i{}; i < s.length(); i++) {
        if(i > 0 && map[s[i]] > map[s[i - 1]]) {
            decimal += map[s[i]] - 2 * map[s[i - 1]];
        } else {
            decimal += map[s[i]];
        }
    }
    return decimal;
}
