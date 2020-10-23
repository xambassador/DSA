#include<iostream>
using namespace std;
#include"../BST.h"

BinarySearchTreeNode<int>* help(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return root;

    BinarySearchTreeNode<int>* node {new BinarySearchTreeNode<int>(root->data)};
    BinarySearchTreeNode<int>* leftChild {root->left};
    root->left = NULL;
    root->left = node;
    BinarySearchTreeNode<int>* leftAns {help(leftChild)};
    BinarySearchTreeNode<int>* rightAns {help(root->right)};
    node->left = leftAns;
    root->right = rightAns;
    return root;
}


void addDuplicates(BinarySearchTreeNode<int>* root) {
    root = help(root);
}


int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    addDuplicates(root);
    printLevelWise(root);
}