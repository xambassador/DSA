#include<iostream>
using namespace std;
#include"../BinaryTree.h"


int sum(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    return root->data + sum(root->left) + sum(root->right);
}


int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    int ans {sum(root)};
    cout << ans << endl;
}