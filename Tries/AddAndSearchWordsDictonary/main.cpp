#include <iostream>
#include <string>
using std::string;

class TrieNode {
    char data;
    bool isTerminal;
    TrieNode** children;

    public:

    TrieNode(char data) {
        this->data = data;
        isTerminal = false;
        children = new TrieNode*[26];
        for (int i{}; i < 26; i++) children[i] = NULL;
    }

    void setTerminal(bool isTerminal) {
        this->isTerminal = isTerminal;
    }

    bool getTerminal() {
        return isTerminal;
    }

    TrieNode** getChildren() {
        return children;
    }
};


class WordDictionary {
    TrieNode* root;

    void insert(TrieNode* root, string s) {
        // If string is empty, then either user provide empty string or we have reached the end of the string
        if (s.empty()) {
            root->setTerminal(true);
            return;
        }

        int index {s[0] - 'a'};
        TrieNode* child;

        if (root->getChildren()[index] != NULL) {
            child = root->getChildren()[index];
        }  else {
            child = new TrieNode(s[0]);
            root->getChildren()[index] = child;
        }

        insert(child, s.substr(1));
        return;
    }


    bool query(TrieNode* root, string s) {
        // If string is empty, then either use give empty string or we have reached the end of the string
        if (s.empty()) {
            // If current node is terminal. Then we successfully found the string
            if (root->getTerminal()) return true;
            return false;
        }

        if (s[0] != '.') {
            int index {s[0] - 'a'};
            if (root->getChildren()[index] == NULL) return false;
            return query(root->getChildren()[index], s.substr(1));
        }

        // If first character is "."
        for (int i{}; i < 26; i++) {
            if (root->getChildren()[i] != NULL) {
                bool isMatchFound {query(root->getChildren()[i], s.substr(1))};
                if (isMatchFound) return true;
            }
        }

        return false;
    }

    public:
    WordDictionary() {
        root = new TrieNode('\0');
    }

    void addWord(string word) {
        insert(root, word);
    }

    bool search(string word) {
        return query(root, word);
    }
};
