#include<iostream>
using std::cout;
using std::endl;
#include"../Tree.h"

void preorder(TreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    for(int i{}; i < root->childrens.size(); i++) preorder(root->childrens[i]);
    return;
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    preorder(root);
}
