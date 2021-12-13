#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;
#include"../BinaryTree.h"

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

vector<Node* > levelWiseLL(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        vector<Node* > ans;
        ans.push_back(NULL);
        return ans;
    }
    vector<Node* > ans;
    queue<BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    Node* head {NULL}, *tail {NULL};
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* front {pendingNodes.front()};
        pendingNodes.pop();
        if(front == NULL) {
            ans.push_back(head);
            head = NULL;
            tail = NULL;
            if(pendingNodes.empty()) break;
            pendingNodes.push(NULL);
            continue;
        }
        Node* node {new Node(front->data)};
        if(head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        if(front->left != NULL) pendingNodes.push(front->left);
        if(front->right != NULL) pendingNodes.push(front->right);
    }
    return ans;
}

int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    vector<Node* > ans {levelWiseLL(root)};
    for(int i{}; i < ans.size(); i++) {
        Node* tmp {ans[i]};
        while(tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }cout << endl;
    }
}
