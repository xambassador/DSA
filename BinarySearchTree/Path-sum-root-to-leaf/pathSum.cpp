#include<iostream>
using namespace std;
#include"../BST.h"


void help(BinarySearchTreeNode<int>* root, int k, vector<int>& v) {
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->data - k == 0){
            v.push_back(root->data);
            for(int i = 0; i<v.size(); i++){
                cout << v[i] << " ";
            }
            cout << endl;
            v.clear();
            return;
        }
        return;
    }
    v.push_back(root->data);
    help(root->left,k - root->data,v);
    help(root->right,k - root->data,v);
}

void rootToleaf(BinarySearchTreeNode<int>* root, int k) {
    vector<int> v;
    help(root, k, v);
}       

int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int k;
    cin >> k;
    rootToleaf(root,k);
}