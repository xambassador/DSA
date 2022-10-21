#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Trie Node
class TrieNode {
    public:
    int rightLeafNodes, leftLeafNodes;
    TrieNode* left;
    TrieNode* right;
    TrieNode() {
        rightLeafNodes = 0;
        leftLeafNodes = 0;
        left = NULL;
        right = NULL;
    }
};


void insert(TrieNode* root, int element) {
    TrieNode* tmp {root};
    for (int i{31}; i >= 0; i--) {
        bool currentBit {(element >> i) & 1};
        if (currentBit == 0) {
            tmp->leftLeafNodes += 1;
            if (tmp->left == NULL) tmp->left = new TrieNode();
            tmp = tmp->left;
        } else {
            tmp->rightLeafNodes += 1;
            if (tmp->right == NULL) tmp->right = new TrieNode();
            tmp = tmp->right;
        }
    }
}


int query(TrieNode* root, int element, int k) {
    if (root == NULL) return 0;
    int count {};
    TrieNode* tmp {root};
    for (int i{31}; i >= 0; i--) {
        bool currentBitOfK {(k >> i) & 1};
        bool currentBitOfElement {(element >> i) & 1};
        if (currentBitOfK == 1) {
            if (currentBitOfElement == 1) {
                count += tmp->rightLeafNodes;
                if (tmp->left == NULL) return count;
                tmp = tmp->left;
            }   else {
                count += tmp->leftLeafNodes;
                if (tmp->right == NULL) return count;
                tmp = tmp->right;
            }
        } else {
            if (currentBitOfElement == 1) {
                if (tmp->right == NULL) return count;
                tmp = tmp->right;
            } else {
                if (tmp->left == NULL) return count;
                tmp = tmp->left;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int* arr {new int[n]};
        for (int i{}; i < n; i++) cin >> arr[i];
        TrieNode* root {new TrieNode()};
        insert(root, 0);
        int pXor {};
        long long count {};
        for (int i{}; i < n; i++) {
            int Xor {pXor ^ arr[i]};
            count += query(root, Xor, k);
            insert(root, Xor);
            pXor = Xor;
        }
        cout << count << endl;
    }
};
