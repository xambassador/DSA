#include <string>
using std::string;

int lengthOfLongestSubstring(string s) {
    const int maximumCharacters {256};
    int mask[maximumCharacters];
    for (int i{}; i < 256; i++) mask[i] = -1;
    int maximumLength {};
    int lastRepeatedPosition {-1};

    for (int i{}; i < s.size(); i++) {
        if (mask[s[i]] != -1 && lastRepeatedPosition < mask[s[i]]) lastRepeatedPosition = mask[s[i]];
        if (i - lastRepeatedPosition > maximumLength) maximumLength = i - lastRepeatedPosition;
        mask[s[i]] = i;
    }

    return maximumLength;
}
