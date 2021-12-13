#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"../BST.h"

void printNodesAtDepthK(BinarySearchTreeNode<int>* root, int k) {
    if(root == NULL || k < 0) return;

    if(k == 0) {
        cout << root->data << " ";
        return;
    }

    printNodesAtDepthK(root->left, k-1);
    printNodesAtDepthK(root->right, k-1);
}


int printAtDistanceK(BinarySearchTreeNode<int>* root, int k, int element) {
    if(root == NULL) return -1;

    if(root->data == element) {
        printNodesAtDepthK(root,k);
        return 0;
    }

    int leftDistance {printAtDistanceK(root->left, k, element)};
    if(leftDistance != -1) {
        if(leftDistance + 1 == k) cout << root->data << " ";
        else printNodesAtDepthK(root->right, k - leftDistance - 2);
        return leftDistance+1;
    }

    int rightDistance {printAtDistanceK(root->right, k,element)};
    if(rightDistance == -1) {
        if(rightDistance + 1 == k) cout << root->data << " ";
        else printNodesAtDepthK(root->left,k-rightDistance-2);
        return rightDistance+1;
    }
    return -1;
}

void printAtKDistance(BinarySearchTreeNode<int>* root, int k, int element) {
    printAtDistanceK(root, k, element);
}

int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int k, element;
    cin >> k;
    cin >> element;
    printAtDistanceK(root, k, element);
}
