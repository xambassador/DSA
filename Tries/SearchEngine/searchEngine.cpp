#include <iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

class TrieNode {
    public:
    TrieNode** children;
    int weight;
    TrieNode() {
        weight = 0;
        children = new TrieNode*[26];
        for (int i{}; i < 26; i++) children[i] = NULL;
    }
};

// -----------------------------------------------------------------------------
void insert(TrieNode* root, string s, int weight) {
    if (s.length() == 0) return;

    TrieNode* child;
    int index {s[0] - 'a'};
    if (root->children[index]) {
        child = root->children[index];
    } else {
        child = new TrieNode();
        child->weight = weight;
        root->children[index] = child;
    }

    if (root->weight < weight) root->weight = weight;
    insert(child, s.substr(1), weight);
    return;
}

// -----------------------------------------------------------------------------
int query(TrieNode* root, string s) {
    if (s.length() == 0) return root->weight;
    int index {s[0] - 'a'};
    if (root->children[index]) return query(root->children[index], s.substr(1));
    else return -1;
}

// -----------------------------------------------------------------------------
int main() {
    int n, q;
    cin >> n >> q;
    TrieNode* root {new TrieNode()};
    for (int i{}; i < n; i++) {
        string s;
        cin >> s;
        int weight;
        cin >> weight;
        insert(root, s, weight);
    }

    while (q--) {
        string s;
        cin >> s;
        cout << query(root,s) << endl;
    }
}
