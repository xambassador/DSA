#include<iostream>
using std::cout;
using std::endl;
#include"../Tree.h"

// method 1
int maxDataNode(TreeNode<int>* root) {
    if(root == NULL) return 0;
    int ans{}, size{root->childrens.size()};
    int* arr{new int[size]};
    for(int i{}; i < size; i++) arr[i] = maxDataNode(root->childrens[i]);
    for(int i{}; i < size; i++) {
        if(arr[i] > ans) ans = arr[i];
    }
    delete arr;
    if(ans > root->data) return ans;
    return root->data;
}

// method 2
int maxDataNode_2(TreeNode<int>* root) {
    if(root == NULL) return 0;
    int ans{root->data};
    for(int i{}; i < root->childrens.size(); i++) {
        int tmpAns{maxDataNode_2(root->childrens[i])};
        if(tmpAns > ans) ans = tmpAns;
    }
    return ans;
}

int main() {
    TreeNode<int>* root{takeInputLevelWise()};
    int maxNode{maxDataNode(root)};
    int maxNode2{maxDataNode_2(root)};
    cout << maxNode << endl;
    cout << maxNode2 << endl;
}
