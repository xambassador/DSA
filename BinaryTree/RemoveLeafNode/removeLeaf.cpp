#include"../BinaryTree.h"

BinaryTreeNode<int>* removeLeaf(BinaryTreeNode<int>* root) {
    if(root == NULL) return NULL;

    if(root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }

    BinaryTreeNode<int>* left {removeLeaf(root->left)};
    BinaryTreeNode<int>* right {removeLeaf(root->right)};
    root->left = left;
    root->right = right;
    return root;
}

int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    root = removeLeaf(root);
    printLevelWise(root);
}
