#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"../BinaryTree.h"

BinaryTreeNode<int>* help(int* preorder, int* inorder, int PreS, int PreE, int InS, int InE) {
    if(InS > InE) return NULL;
    //For search root in Inorder
    int rootIndex{-1}, root{preorder[PreS]};
    if(root == -1) return NULL;
    for(int i{InS}; i <= InE; i++) {
        if(inorder[i] == root) {
            rootIndex = i;
            break;
        }
    }
    int LeftInStart{InS}, LeftInEnd{rootIndex - 1}, LeftPreStart{PreS + 1}, LeftPreEnd{LeftInEnd - LeftInStart + LeftPreStart};
    int RightPreStart{LeftPreEnd + 1}, RightPreEnd{PreE}, RightInStart{rootIndex + 1}, RightInEnd{InE};

    BinaryTreeNode<int>* root_node{new BinaryTreeNode<int>(root)};
    root_node->left = help(preorder, inorder, LeftPreStart, LeftPreEnd, LeftInStart, LeftInEnd);
    root_node->right = help(preorder, inorder, RightPreStart, RightPreEnd, RightInStart, RightInEnd);
    return root_node;
}

BinaryTreeNode<int>* constructTree(int* preorder, int* inorder, int size) {
    return help(preorder, inorder, 0,size-1,0,size-1);
}

int main(){
    int pre[]{8,3,1,6,4,7,10,14,13};
    int in[]{1,3,4,6,7,8,10,13,14};
    BinaryTreeNode<int>* root{constructTree(pre,in,sizeof(pre)/sizeof(int))};
    print(root);
}
