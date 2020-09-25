#include<iostream>
using namespace std;
#include"../Tree.h"

void postorder(TreeNode<int>* root){
    if(root == NULL) return;

    for(int i{}; i<root->childrens.size(); i++){
        postorder(root->childrens[i]);
    }

    cout << root->data << " ";
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    postorder(root);
}