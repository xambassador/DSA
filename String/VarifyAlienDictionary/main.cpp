#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::min;
using std::unordered_map;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------------------

bool compareArray(string& s, string& t, int* alienDictionary) {
    int sLength {(int)s.length()};
    int tLength {(int)t.length()};
    int windowLength {min(sLength, tLength)};
    int i{};
    while (i < windowLength) {
        int leftCharPosition {alienDictionary[s[i] - 'a']};
        int rightCharPosition {alienDictionary[t[i] - 'a']};
        if (leftCharPosition < rightCharPosition) return true;
        if (leftCharPosition > rightCharPosition) return false;
        i++;
    }
    if (sLength <= tLength) return true;
    return false;
}

bool isAlienSortedUsingArray(vector<string>& words, string order) {
    if (words.size() == 1) return true;
    int alienDictionary[26];
    // O(order length)
    for (int i{}; i < order.length(); i++) alienDictionary[order[i] - 'a'] = i;
    // O(words size * word length)
    for (int i{1}; i < words.size(); i++) {
        // O(word length [i - 1] + word length [i])
        if (!compareArray(words[i - 1], words[i], alienDictionary)) return false;
    }
    return true;
}

// -----------------------------------------------------------------------------------------
bool compare(string& s, string& t, unordered_map<char, int>& alienDictionary) {
    int sLength {(int)s.length()};
    int tLength {(int)t.length()};
    int windowLength {min(sLength, tLength)};
    int i{};
    while (i < windowLength) {
        int leftCharPosition {alienDictionary[s[i]]};
        int rightCharPosition {alienDictionary[t[i]]};
        if (leftCharPosition < rightCharPosition) return true;
        if (leftCharPosition > rightCharPosition) return false;
        i++;
    }
    if (sLength == tLength) return true;
    if (sLength <= tLength) return true;
    return false;
}

bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() == 1) return true;
    unordered_map<char, int> alienDictionary;
    // O(order length)
    for (int i{}; i < order.length(); i++) alienDictionary[order[i]] = i;
    // O(words size * word length)
    for (int i{1}; i < words.size(); i++) {
        // O(word length [i - 1] + word length [i])
        if (!compare(words[i - 1], words[i], alienDictionary)) return false;
    }
    return true;
}

// -----------------------------------------------------------------------------------------
int main () {
    vector<string> words {"apple","app"};
    string order {"abcdefghijklmnopqrstuvwxyz"};
    cout << isAlienSortedUsingArray(words, order) << endl;
    return 0;
}
