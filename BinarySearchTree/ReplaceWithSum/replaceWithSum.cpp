#include<iostream>
using namespace std;
#include"../BST.h"

int Sum(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return 0;
    return root->data + Sum(root->left) + Sum(root->right);
}


int help(BinarySearchTreeNode<int>* root, int sum) {
    if(root == NULL) return 0;

    int rightSum {Sum(root->right)};
    
    root->data = root->data + rightSum + sum;
    
    int leftans {help(root->left, root->data)};
    int ans;
    if(sum == 0) {
        ans = help(root->right,sum);
    }else{
        ans = help(root->right, sum);
    }
    return ans;
}

void replaceSum(BinarySearchTreeNode<int>* root){
    int ans {help(root,0)};
}


int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    replaceSum(root);
    printLevelWise(root);
    delete root;
}