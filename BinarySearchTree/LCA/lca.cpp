#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"../BST.h"

BinarySearchTreeNode<int>* lcaHelp(BinarySearchTreeNode<int>* root, int n1, int n2 ) {
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2) {
        return root;
    }
    BinarySearchTreeNode<int>* leftAns {lcaHelp(root->left,n1,n2)};
    BinarySearchTreeNode<int>* rightAns {lcaHelp(root->right,n1,n2)};

    if(leftAns != NULL && rightAns == NULL) return leftAns;
    else if(leftAns == NULL && rightAns == NULL) return NULL;
    else if(leftAns != NULL && rightAns != NULL) return root;
}

int lca(BinarySearchTreeNode<int>* root, int n1, int n2) {
    BinarySearchTreeNode<int>* ans {lcaHelp(root,n1,n2)};
    if(ans == NULL) return -1;
    return ans->data;
}

int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int n1,n2;
    cin >> n1 >> n2;
    int ans {lca(root,n1,n2)};
    cout << ans << endl;
}
