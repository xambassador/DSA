#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using std::unordered_map;
using std::vector;
using std::string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

void split(vector<string>& words, string s) {
    string word {};
    stringstream ss(s);
    while (getline(ss, word, ' ')) {
        words.push_back(word);
    }
}

// -----------------------------------------------------------------------------
bool wordPattern(string pattern, string s) {
    vector<string> words;
    split(words, s);
    if (words.size() != pattern.size()) return false;
    unordered_map<char, string> map;
    for (int i{}; i < words.size(); i++) {
        if (map.find(pattern[i]) == map.end()) {
            for (auto it = map.begin(); it != map.end(); it++) {
                if (it->second == words[i]) return false;
            }
            map[pattern[i]] = words[i];
        } else {
            if (map[pattern[i]] != words[i]) return false;
        }
    }

    return true;
}

// -----------------------------------------------------------------------------
int main () {
    string pattern {"abba"};
    string s {"dog cat cat dog"};
    cout << wordPattern(pattern, s) << endl;
}
