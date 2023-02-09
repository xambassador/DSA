#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using std::unordered_set;
using std::unordered_map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class TrieNode {
    public:
    TrieNode** children;
    bool isTerminal;
    char data;

    TrieNode(char data) {
        this->data = data;
        this->isTerminal = false;
        this->children = new TrieNode*[26];
        for (int i{}; i < 26; i++) this->children[i] = NULL;
    }
};

// -----------------------------------------------------------------------------------------
void insert(TrieNode* root, string s) {
    if (s.empty()) {
        root->isTerminal = true;
        return;
    }

    int index {s[0] - 'a'};
    TrieNode* child;
    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        child = new TrieNode(s[0]);
        root->children[index] = child;
    }

    insert(child, s.substr(1));
    return;
}

// -----------------------------------------------------------------------------------------
bool query(TrieNode* root, string word) {
    if (word.empty()) {
        if (root->isTerminal) {
            return true;
        }
        return false;
    }

    int index {word[0] - 'a'};
    if (root->children[index]) {
        return query(root->children[index], word.substr(1));
    }
    return false;
}

// -----------------------------------------------------------------------------------------
// Naive approach.
long long distinctNames(vector<string>& ideas) {
    TrieNode* root {new TrieNode('\0')};
    for (string& s : ideas) {
        insert(root, s);
    }

    unordered_map<string, bool> map;

    long long int ans {};
    for (int i{}; i < ideas.size(); i++) {
        for (int j{}; j < ideas.size(); j++) {
            if (i == j) continue;
            string ideaA {ideas[j][0] + ideas[i].substr(1)};
            string ideaB {ideas[i][0] + ideas[j].substr(1)};
            bool isIdeaAOk {false};
            bool isIdeaBOk {false};

            // If ideaA is not encounter before.
            if (map.find(ideaA) == map.end()) {
                // check if it is inside trie
                bool isAvailableInTrie {query(root, ideaA)};

                // if ideaA is inside the trie. Then it violate rule.
                if (isAvailableInTrie) {
                    map[ideaA] = true;
                    continue;
                }

                // if ideaA is not inside the trie.
                map[ideaA] = false;
                isIdeaAOk = true;
            }

            // If ideaA is encounter before
            else {
                bool isInsideTrie {map[ideaA]};
                if (isInsideTrie) {
                    // ideaA is already into ideas array.
                    continue;
                }

                isIdeaAOk = true;
            }

            // If ideaB is not encounter before.
            if (map.find(ideaB) == map.end()) {
                bool isAvailableInTrie {query(root, ideaB)};
                if (isAvailableInTrie) {
                    map[ideaB] = true;
                    continue;
                }

                isIdeaBOk = true;
                map[ideaB] = false;
            } else {
               bool isInsideTrie {map[ideaB]};
               if (isInsideTrie) {
                continue;
               }

               isIdeaBOk = true;
            }

            if (isIdeaAOk && isIdeaBOk) {
                ans++;
            }
        }
    }

    return ans;
}


long long distinctNamesGroupBy(vector<string>& ideas) {
    unordered_set<string> groups[26];
    for (string& s : ideas) {
        groups[s[0] - 'a'].insert(s.substr(1));
    }

    long long int ans {};
    for (int i{}; i < 25; i++) {
        for (int j{i + 1}; j < 26; j++) {
            int commonSuffix {};
            for (auto& ideaA : groups[i]) {
                if (groups[j].count(ideaA)) {
                    commonSuffix++;
                }
            }

            ans += 2LL * (groups[i].size() - commonSuffix) * (groups[j].size() - commonSuffix);
        }
    }

    return ans;
}


// -----------------------------------------------------------------------------------------
int main () {
    vector<string> ideas {"coffee","donuts","time","toffee"};
    // vector<string> ideas {"lack","back"};
    // cout << distinctNames(ideas) << endl;
    cout << distinctNamesGroupBy(ideas) << endl;
}
