#include<iostream>
#include<climits>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
#include"../BST.h"

bool isBST(BinarySearchTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
    if(root == NULL) return true;

    if(root->data < min || root->data > max) return false;

    return isBST(root->left,min, root->data-1) && isBST(root->right, root->data+1,max);
}


BinarySearchTreeNode<int>* help(int* arr, int start, int end) {
    if(start > end) return NULL;

    int mid {(start+end)/2};
    BinarySearchTreeNode<int>* node {new BinarySearchTreeNode<int>(arr[mid])};
    node->left = help(arr, start, mid - 1);
    node->right = help(arr, mid + 1, end);
    return node;
}


BinarySearchTreeNode<int>* constructBST(int* arr, int n) {
    return help(arr,0,n-1);
}


int main() {
    int n;
    cin >> n;
    int* arr {new int[n]};
    for(int i{}; i < n; i++) cin >> arr[i];
    BinarySearchTreeNode<int>* root {constructBST(arr,n)};
    print(root);
    cout << boolalpha << isBST(root) << endl;

    delete arr;
    delete root;
}
