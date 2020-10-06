#include<iostream>
using namespace std;
#include "../BinaryTree.h"

void mirror(BinaryTreeNode<int>* root) {
    if(root == NULL) return;

    if(root->left != NULL && root->right != NULL) {
        BinaryTreeNode<int>* tmp {root->left};
        root->left = root->right;
        root->right = tmp;
    }

    else if(root->left != NULL && root->right == NULL) {
        root->right = root->left;
        root->left = NULL;
    }

    else if(root->left == NULL && root->right != NULL) {
        root->left = root->right;
        root->right = NULL;
    }

    mirror(root->left);
    mirror(root->right);
}

void Print(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* front {pendingNodes.front()};
        pendingNodes.pop();
        if(front == NULL) {
            if(pendingNodes.empty()) break;
            cout << endl;
            pendingNodes.push(NULL);
            continue;
        }
        cout << front->data << " ";
        if(front->left != NULL) pendingNodes.push(front->left);
        if(front->right != NULL) pendingNodes.push(front->right); 
    }
}

int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    mirror(root);
    Print(root);
}