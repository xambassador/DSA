#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

const int MAX_SIZE {26};

// -----------------------------------------------------------------------------
vector<int> findAnagrams(string s, string p) {
    // To be anagram, the length of s and p must be equal and all the characters have same frequency.
    if (s.length() < p.length()) return {};
    vector<int> result;
    vector<int> frequency(MAX_SIZE, 0);
    vector<int> window(MAX_SIZE, 0);

    // Add an entry for each character in frequency character and window.
    for (int i{}; i < p.length(); i++) {
        frequency[p[i] - 'a']++;
        window[s[i] - 'a']++;
    }

    // Check if the first window is anagram or not.
    if (frequency == window) result.push_back(0);

    // Process rest of the window.
    for (int i{(int)p.length()}; i < s.length(); i++) {
        // Add current character in window.
        window[s[i] - 'a']++;
        // Remove first character of previous window.
        window[s[i - p.length()] - 'a']--;

        // Check if the current window is anagram or not.
        if (window == frequency) result.push_back(i - p.length() + 1);
    }

    return result;
}

// -----------------------------------------------------------------------------
int main () {
    string s, p;
    cin >> s >> p;
    vector<int> result{findAnagrams(s, p)};
    for (int i{}; i < result.size(); i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}
