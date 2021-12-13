#include<iostream>
using std::cout;
using std::endl;
#include"../Tree.h"

void printAtDepth(TreeNode<int>* root, int k) {
    if(root == NULL) return;
    if(k == 0) {
        cout << root->data << endl;
        return;
    }
    for(int i{}; i < root->childrens.size(); i++) printAtDepth(root->childrens[i], k - 1);
}

int main() {
    TreeNode<int>* root{takeInputLevelWise()};
    printAtDepth(root,3);
}

// 10 2 20 30 1 40 2 50 60 0 2 70 80 2 90 100 0 0 0 0
