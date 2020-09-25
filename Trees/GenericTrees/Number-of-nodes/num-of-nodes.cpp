#include<iostream>
using namespace std;
#include"../Tree.h"

int numNodes(TreeNode<int>* root){
    if(root == NULL) return 0;

    int ans{};
    for(int i{}; i<root->childrens.size(); i++){
        ans += numNodes(root->childrens[i]);
    }
    return ans+1;
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    int ans{numNodes(root)};
    cout << ans << endl;
}