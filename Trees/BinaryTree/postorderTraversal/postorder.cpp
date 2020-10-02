#include<iostream>
using namespace std;
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