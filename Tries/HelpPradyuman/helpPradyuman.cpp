#include <iostream>
#include <queue>
using std::queue;
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------
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

// -----------------------------------------------------------------------------
bool query(TrieNode* root, string s, string word = "") {
    // Search string is empty
    if (s.empty()) {
        // Check if root is terminal or not. if yes then there is one word that ends with root->data.
        if (root->isTerminal) {
            // print that word
            cout << word << endl;

            // Store this word
            string tmp {word};

            // Now, a search string that enter by user is finish. Now, we need to show all possible strings
            // That starts with or that have prefix enter by user.
            for (int i{}; i < 26; i++) {
                if (root->children[i]) {
                    word = word + root->children[i]->data;
                    query(root->children[i], s, word);
                    word = tmp;
                }
            }
            return true;
        } else {
            string tmp {word};
            for (int i{}; i < 26; i++) {
                if (root->children[i]) {
                    word = word + root->children[i]->data;
                    query(root->children[i], s, word);
                    word = tmp;
                }
            }
            return true;
        }
    }

    int index {s[0] - 'a'};
    bool ans;
    if (root->children[index] != NULL) {
        string newWord {word + s[0]};
        ans = query(root->children[index], s.substr(1), newWord);
    } else {
        cout << "No suggestions" << endl;
        ans = false;
    }
    return ans;
}

// -----------------------------------------------------------------------------
void print(TrieNode* root) {
    queue<TrieNode*> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TrieNode* tmp {nodes.front()};
        nodes.pop();
        cout << tmp->data << " : ";
        for (int i{}; i < 26; i++) {
            if (tmp->children[i]) {
                nodes.push(tmp->children[i]);
                cout << tmp->children[i]->data << ", ";
            }
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    TrieNode* root {new TrieNode('\0')};
    for (int i{}; i < n; i++) {
        string s;
        cin >> s;
        insert(root, s);
    }

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        bool ans {query(root, s)};
        if (!ans) insert(root, s);
    }
}
