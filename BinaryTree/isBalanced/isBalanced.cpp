#include<iostream>
using namespace std;
#include"../BinaryTree.h"

class Pair {
    public:
    int height;
    bool balanced;
};

Pair help(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair ans;
        ans.height = 0;
        ans.balanced = true;
        return ans;
    }

    if(root->left == NULL && root->right == NULL) {
        Pair ans;
        ans.height = 1;
        ans.balanced = true;
        return ans;
    }

    Pair leftAns {help(root->left)};
    Pair rightAns {help(root->right)};
    Pair ans;
    if(leftAns.balanced == false || rightAns.balanced == false) {
        ans.height = 1 + max(leftAns.height, rightAns.height);
        ans.balanced = false;
    }else {
        int diff {abs(leftAns.height - rightAns.height)};
        if(diff < 2) {
            ans.height = 1 + max(leftAns.height, rightAns.height);
            ans.balanced = true;
        }else {
            ans.height = 1 + max(leftAns.height, rightAns.height);
            ans.balanced = false;
        }
    }
    return ans;
}

bool isBalanced(BinaryTreeNode<int>* root) {
    return help(root).balanced;
}


int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    bool ans {isBalanced(root)};
    cout << boolalpha << ans << endl;
}