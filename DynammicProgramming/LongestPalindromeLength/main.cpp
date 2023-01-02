#include <iostream>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int longestPalindrome(string s) {
    unordered_map<char, int> map;
    for (int i{}; i < s.length(); i++) map[s[i]] += 1;
    bool isKeyWithValueOneEncounter {false};
    int maxLength {};
    for (unordered_map<char, int>::iterator it {map.begin()}; it != map.end(); it++) {
        int count {it -> second};

        // If key's value is 1.
        if (count == 1) {
            if (!isKeyWithValueOneEncounter) {
                isKeyWithValueOneEncounter = true;
                maxLength += 1;
            }
            continue;
        }

        // If key's value is odd.
        if (count % 2 != 0) {
            // Process all even characters. Ex: count = 7. Process all 6 chars.
            maxLength += count - 1;
            // For remaining one character.
            if (!isKeyWithValueOneEncounter) {
                maxLength += 1;
                isKeyWithValueOneEncounter = true;
            }
            continue;
        }

        // If key's value is even
        if (count % 2 == 0) maxLength += count;
    }

    return maxLength;
}

// -----------------------------------------------------------------------------
int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s) << endl;
}
