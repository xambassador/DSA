#include<iostream>
using namespace std;
#include"../Tree.h"

int sumOfNodes(TreeNode<int>* root){
    if(root == NULL) return 0;
    int ans{};
    for(int i{}; i<root->childrens.size(); i++){
        ans += sumOfNodes(root->childrens[i]);
    }
    return ans+root->data;
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    int sum{sumOfNodes(root)};
    cout << sum << endl;
}