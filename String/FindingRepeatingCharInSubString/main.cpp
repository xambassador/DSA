#include <iostream>
#include <string>
#include <algorithm>
using std::max;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

int characterReplacement(string s, int k) {
    // If string s length is equal to k, then we can replace all the characters
    if (s.length() == k) return k;
    int maxLen {};
    int start {}, end {};
    int maxCount {};
    // count array to store the count of characters in the current window
    int count[26] {0};
    // start and end are the start and end of the current window
    while (end < s.length()) {
        // Increment the count of the current character
        count[s[end] - 'A']++;
        // Update the maxCount
        maxCount = max(maxCount, count[s[end] - 'A']);
        // If the current window size is greater than the maxCount + k, then
        // we need to shrink the window
        while (end - start + 1 - maxCount > k) {
            count[s[start] - 'A']--;
            start++;
        }
        // Update the maxLen
        maxLen = max(maxLen, end - start + 1);
        end++;
    }
    return maxLen;
}


// -----------------------------------------------------------------------------
int main () {
    string s {"ABAB"};
    int k {2};
    cout << characterReplacement(s, k) << endl;
    return 0;
}
