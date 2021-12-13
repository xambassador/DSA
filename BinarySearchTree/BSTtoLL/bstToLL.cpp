#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"../BST.h"
class Node {
    public:
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};
class Pair {
    public:
    Node* head;
    Node* tail;
};

Pair help(BinarySearchTreeNode<int>* root) {
    if(root == NULL) {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    if(root->left == NULL && root->right == NULL) {
        Pair ans;
        Node* node {new Node(root->data)};
        ans.head = node;
        ans.tail = node;
        return ans;
    }

    Pair left {help(root->left)};
    Node* node {new Node(root->data)};
    if(left.head == NULL) {
        left.head = node;
        left.tail = node;
    } else left.tail->next = node;
    Pair right {help(root->right)};
    node->next = right.head;

    Pair ans;
    ans.head = left.head;
    ans.tail = right.tail;
    return ans;
}


Node* BSTtoLL(BinarySearchTreeNode<int>* root) {
    return help(root).head;
}

int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    Node* head {BSTtoLL(root)};
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    delete root;
}
