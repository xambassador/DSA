#include<iostream>
using namespace std;
#include"../Tree.h"

void printLeafNodes(TreeNode<int>* root){
    if(root == NULL) return;

    if(root->childrens.size() == 0){
        cout << root->data << " ";
        return;
    }

    for(int i{}; i<root->childrens.size(); i++){
        printLeafNodes(root->childrens[i]);
    }
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    printLeafNodes(root);
}