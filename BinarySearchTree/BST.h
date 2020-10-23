#include<queue>
#include"BinarySearchTree.h"

void printLevelWise(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return;
    queue<BinarySearchTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()) {
        BinarySearchTreeNode<int>* front {pendingNodes.front()};
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


void print(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << ": ";
    if(root->left != NULL) cout << "L " << root->left->data << " ,";
    else cout << "-1" << " ,";
    if(root->right != NULL) cout << "R " << root->right->data << endl;
    else cout << "-1" << endl;
    print(root->left);
    print(root->right); 
}

BinarySearchTreeNode<int>* takeInput(){
    int rootData;
    cin >> rootData;
    if(rootData == -1) return NULL;
    BinarySearchTreeNode<int>* root {new BinarySearchTreeNode<int>(rootData)};
    queue<BinarySearchTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinarySearchTreeNode<int>* front {pendingNodes.front()};
        int data;
        cin >> data;
        if(data != -1) {
            BinarySearchTreeNode<int>* node {new BinarySearchTreeNode<int>(data)};
            front->left = node;
            pendingNodes.push(node);
        }
        cin >> data;
        if(data != -1) {
            BinarySearchTreeNode<int>* node {new BinarySearchTreeNode<int>(data)};
            front->right = node;
            pendingNodes.push(node);
        }
        pendingNodes.pop();
    }
    return root;
}