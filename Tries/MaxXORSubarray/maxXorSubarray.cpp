#include <iostream>
#include <climits>
using namespace std;

// Trie Node
class TrieNode {
    public:
    int value;
    TrieNode* arr[2];
    TrieNode() {
        value = 0;
        arr[0] = NULL;
        arr[1] = NULL;
    }
};

void insert(TrieNode* root, int pXor) {
    TrieNode* tmp {root};
    for (int i{31}; i >= 0; i--) {
        bool currentBit {(1 << i) & pXor};
        if (!tmp->arr[currentBit]) tmp->arr[currentBit] = new TrieNode();
        tmp = tmp->arr[currentBit];
    }
    tmp->value = pXor;
}

int query(TrieNode* root, int pXor) {
    TrieNode* tmp {root};
    for (int i{31}; i >= 0; i--) {
        bool currentBit {(1 << i) & pXor};
        if (tmp->arr[1-currentBit]) tmp = tmp->arr[1-currentBit];
        else if (tmp->arr[currentBit]) tmp = tmp->arr[currentBit];
    }
    return pXor ^ (tmp->value);
}

int maxSubArrayXor(int* arr, int n) {
    TrieNode* root {new TrieNode()};
    insert(root, 0);
    int result {INT_MIN};
    int pXor {};
    for (int i{}; i < n; i++) {
        pXor = pXor ^ arr[i];
        insert(root, pXor);
        int ans {query(root, pXor)};
        result = max(result, ans);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int* arr {new int[n]};
    for (int i{}; i < n; i++) cin >> arr[i];
    cout << maxSubArrayXor(arr,n) << endl;
}
