#include<iostream>
using std::cout;
#include"../BinaryTree.h"

void postorder(BinaryTreeNode<int>* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    BinaryTreeNode<int>* root{TakeInputLevelWise()};
    postorder(root);
}
