#include<iostream>
using namespace std;
#include"../Tree.h"

TreeNode<int>* nextInt(TreeNode<int>* root, int x){
    if(root == NULL) return NULL;

    vector<TreeNode<int>*> arr;
    for(int i{}; i<root->childrens.size(); i++){
        TreeNode<int>* ans{nextInt(root->childrens[i],x)};
        if(ans != NULL) arr.push_back(ans);
    }

    if(arr.empty()){
        if(root->data > x) return root;
        else return NULL;
    }

    TreeNode<int>* smallest{arr[0]};
    for(int i{1}; i<arr.size(); i++){
        if(arr[i]->data < smallest->data){
            smallest = arr[i];
        }
    }
    if(root->data > x && root->data < smallest->data){
        smallest = root;
    }
    return smallest;
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    int x;
    cin >> x;
    TreeNode<int>* ans{nextInt(root,x)};
    cout << ans->data << endl;
}

// 10 3 20 30 15 2 40 50 2 60 70 1 100 0 0 2 70 80 0 0 0 1 100 0