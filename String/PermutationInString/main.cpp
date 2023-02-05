#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

bool checkInclusion(string s1, string s2) {
    // If s2 is less than s1, then s2 can't contain s1
    if (s1.size() > s2.size()) return false;

    // Create a frequency array containing the frequency of each character in s1
    vector<int> frequency(26, 0);
    vector<int> window(26, 0);

    // Fill both the frequency and window array with the frequency of each character in s1 and s2
    for (int i{}; i < s1.size(); i++) {
        frequency[s1[i] - 'a']++;
        window[s2[i] - 'a']++;
    }

    // Compare the frequency array with the window array
    if (frequency == window) return true;

    for (int i{(int)s1.size()}; i < s2.size(); i++) {
        // Add the next character to the window and remove the first character from the window
        window[s2[i] - 'a']++;
        window[s2[i - s1.size()] - 'a']--;
        if (frequency == window) return true;
    }

    return false;
}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2) << endl;
    return 0;
}
