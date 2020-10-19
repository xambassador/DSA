#include<iostream>
using namespace std;
#include"../BST.h"


BinarySearchTreeNode<int>* search(BinarySearchTreeNode<int>* root, int x) {
    if(root == NULL) return NULL;

    if(root->data == x) {
        return root;
    }
    return root->data > x ? search(root->left,x) : search(root->right, x);
}


int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int x;
    cin >> x;
    BinarySearchTreeNode<int>* ans {search(root,x)};
    if(ans) cout << ans->data << endl;
}