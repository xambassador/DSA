#include<iostream>
using std::cout;
using std::endl;
#include"../BinaryTree.h"

void LevelOrder(BinaryTreeNode<int>* root) {
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

int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    LevelOrder(root);
}
