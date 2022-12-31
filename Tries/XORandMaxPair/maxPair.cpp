#include <iostream>
#include <climits>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

struct TrieNode {
    TrieNode* left;
    TrieNode* right;
};

// -----------------------------------------------------------------------------
// Insert in trie
void insert (TrieNode* root, int n) {
    TrieNode* curr {root};
    for (int i{31}; i >= 0; i--) {
        // Extract bit at ith position
        int bit {(n >> i) & 1};

        // If ith bit is 0 then move on left side
        if (bit == 0) {
            // Check if left node is exists or not
            // If not exists then create new one
            if (!curr->left) curr->left = new TrieNode();
            curr = curr->left;
        } else {
            // Check if right node is exists or not
            // If not then create
            if (!curr->right) curr->right = new TrieNode();
            curr = curr->right;
        }
    }
}

// -----------------------------------------------------------------------------
//  Find maximum pair
int findMaxXorPair (TrieNode* root, int* arr, int n) {
    int maxXor {INT_MIN};
    for (int i{}; i < n; i++) {
        int value {arr[i]}, currentXor {};
        TrieNode* curr {root};
        for (int j{31}; j >= 0; j--) {
            int b {(value >> j) & 1};

            if (b != 0) {
                if (curr->left) {
                    curr = curr->left;
                } else {
                    currentXor += pow(2, j);
                    curr = curr->right;
                }
            }

            if (b == 0) {
                if (curr->right) {
                    currentXor += pow(2, j);
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            }

            if (maxXor < currentXor) maxXor = currentXor;
        }
    }
    return maxXor;
}

// -----------------------------------------------------------------------------
int main() {
    int n;
    cin >> n;
    int* arr {new int[n]};
    for (int i{}; i < n; i++) cin >> arr[i];
    TrieNode* root {new TrieNode()};
    for (int i{}; i < n; i++) insert(root, arr[i]);
    cout << findMaxXorPair(root, arr, n) << endl;
}
