#include<iostream>
using namespace std;
#include"../BinaryTree.h"

int countNode(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}


int main(){
    BinaryTreeNode<int>* root{TakeInputLevelWise()};
    int ans{countNode(root)};
    cout << ans << endl;
}