#include<algorithm>
#include<iostream>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
#include"../BST.h"

class Pair {
    public:
    int height;
    int max;
    int min;
    bool isBST;
};

Pair help(BinarySearchTreeNode<int>* root) {
    if(root == NULL) {
        Pair ans;
        ans.height = 0;
        ans.isBST = true;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        return ans;
    }

    if(root->left == NULL && root->right == NULL) {
        Pair ans;
        ans.height = 1;
        ans.isBST = true;
        ans.max = root->data;
        ans.min = root->data;
        return ans;
    }

    Pair left {help(root->left)};
    Pair right {help(root->right)};
    Pair ans;

    // if root is bst
    bool isBST {left.max <= root->data && right.min >= root->data && left.isBST && right.isBST};
    if(isBST) {
        ans.height = 1 + max(left.height, right.height);
        ans.isBST = true;
        ans.max = max(root->data, max(left.max, right.max));
        ans.min = min(root->data, min(left.min, right.min));
    } else {
        ans.height = max(left.height, right.height);
        ans.isBST = false;
        ans.max = max(root->data, max(left.max, right.max));
        ans.min = min(root->data, min(left.min, right.min));
    }
    return ans;
}


int largestBST(BinarySearchTreeNode<int>* root)  {
    Pair ans {help(root)};
    return ans.height;
}

int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int ans {largestBST(root)};
    cout << ans << endl;
}
