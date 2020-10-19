#include<iostream>
using namespace std;
#include"../BST.h"

void printInRange(BinarySearchTreeNode<int>* root, int x, int y) {
    if(root == NULL) return;
    if(x < root->data) {
        printInRange(root->left,x,y);
    }
    if(x <= root->data && y >= root->data) {
        cout << root->data << " ";
    }
    if(y >= root->data) {
        printInRange(root->right,x,y);
    }
}

int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int x1,x2;
    cin >> x1, x2;
    printInRange(root,x1,x2);
}