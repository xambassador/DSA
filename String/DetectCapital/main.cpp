#include <iostream>
#include <string>
using std::boolalpha;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

bool isCapital(char& c) {
    return c >= 'A' && c <= 'Z';
}

// -----------------------------------------------------------------------------
bool checkForCase(bool& isLetterACapital, bool& isLetterBCapital) {
    // Example: I N
    if (isLetterACapital && isLetterBCapital) {
        return true; // Indicate for Capital letters
    }
    // Example: I n
    if (isLetterACapital && !isLetterBCapital) {
        return false; // Indicate for small letters;
    }
    // Example: i n
    if (!isLetterACapital && !isLetterBCapital) {
        return false;
    }

    // This is for case: i N. Which handle already.
    // So control never reach here.
    return false;
}

// -----------------------------------------------------------------------------
bool detectCapitalUse(string word) {
    int len {(int) word.length()};
    if (len == 0) return true;
    if (len == 1) return true;
    if (len == 2) {
        bool isFirstCharCapital {isCapital(word[0])};
        bool isSecondCharCapital {isCapital(word[1])};
        // Check for case like: iN
        if (!isFirstCharCapital && isSecondCharCapital) return false;
        return true;
    }
    bool isFirstCharCapital {isCapital(word[0])};
    bool isSecondCharCapital {isCapital(word[1])};
    // check first two letters: Example: i N
    if (!isFirstCharCapital && isSecondCharCapital) return false;
    bool needToCheckCapital {checkForCase(isFirstCharCapital, isSecondCharCapital)};
    for (int i{2}; i < len; i++) {
        // Check for cases like: I (N), i (n)
        if ((isCapital(word[i]) && needToCheckCapital) || (!isCapital(word[i]) && !needToCheckCapital)) {
            continue;
        }
        // Check for cases like: i (N), Eng (L)
        if ((!isCapital(word[i]) && needToCheckCapital) || (isCapital(word[i]) && !needToCheckCapital)) {
            return false;
        }
    }
    return true;
}

// -----------------------------------------------------------------------------
int main() {
    string word;
    cin >> word;
    cout << boolalpha << detectCapitalUse(word) << endl;
}
