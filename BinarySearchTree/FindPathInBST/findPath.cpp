#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
#include"../BST.h"

vector<int>* RootToNodePath(BinarySearchTreeNode<int>* root, int x) {
    if(root == NULL) return NULL;

    if(root->data == x) {
        vector<int>* v {new vector<int>};
        v->push_back(x);
        return v;
    }

    vector<int>* ans {RootToNodePath(root->left,x)};
    if(ans != NULL) {
        ans->push_back(root->data);
        return ans;
    }

    vector<int>* rans {RootToNodePath(root->right,x)};
    if(rans != NULL) {
        rans->push_back(root->data);
        return rans;
    }
    return NULL;
}

int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    int x;
    cin >> x;
    vector<int>* v {RootToNodePath(root,x)};
    for(int i{}; i < v->size(); i++) cout << v->at(i) << " ";
}
