#include<queue>
#include"BinaryTreeNode.h"


BinaryTreeNode<int>* TakeInput() {
    int data;
    cout << "Enter data : ";
    cin >> data;
    if(data == -1) return NULL; // -1 represent NULL tree
    BinaryTreeNode<int>* node{new BinaryTreeNode<int>(data)};
    node->left = TakeInput();
    node->right = TakeInput();
    return node;
}

BinaryTreeNode<int>* TakeInputLevelWise() {
    int data;
    cout << "Enter root data :  ";
    cin >> data;
    BinaryTreeNode<int>* root{new BinaryTreeNode<int>(data)};
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* front{pendingNodes.front()};
        int tdata;
        cout << "Enter childs of " << front->data << endl;
        cout << "Enter left child " << endl;
        cin >> tdata;
        if(tdata != -1) {
            front->left = new BinaryTreeNode<int>(tdata);
            pendingNodes.push(front->left);
        }
        else front->left = NULL;
        cout << "Enter right child " << endl;
        cin >> tdata;
        if(tdata != -1) { 
            front->right = new BinaryTreeNode<int>(tdata);
            pendingNodes.push(front->right);
        }
        else front->right = NULL;
        pendingNodes.pop();
    }
    return root;
}

void print(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << ":";
    if(root->left != NULL) cout << root->left->data << "L,";
    if(root->right != NULL) cout << root->right->data << "R" << endl;
    else cout << endl;
    print(root->left);
    print(root->right);
}

void printLevelWise(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
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