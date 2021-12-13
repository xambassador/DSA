#include<iostream>
using std::cout;
#include"../BinaryTree.h"

void preorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    BinaryTreeNode<int>* root{TakeInputLevelWise()};
    preorder(root);
}
