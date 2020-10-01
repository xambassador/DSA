#include<iostream>
using namespace std;
#include"../Tree.h"

void help(TreeNode<int>* root, int d){
    if(root == NULL) return;

    root->data = d;
    for(int i{}; i<root->childrens.size(); i++){
        help(root->childrens[i], d+1);
    }
}


void replaceWithDepth(TreeNode<int>* root){
    help(root,0);
}

void printL(TreeNode<int>* root){
    if(root == NULL) return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    cout << root->data << endl;
    while(!pendingNodes.empty()){
        TreeNode<int>* front{pendingNodes.front()};
        for(int i{}; i<front->childrens.size(); i++){
            pendingNodes.push(front->childrens[i]);
            cout << front->childrens[i]->data << " ";
            if(i == front->childrens.size()-1){
                cout << endl;
            }
        }
        pendingNodes.pop();
    }
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    replaceWithDepth(root);
    printL(root);
}