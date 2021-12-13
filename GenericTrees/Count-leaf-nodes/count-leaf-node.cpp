#include<iostream>
using std::cout;
using std::endl;
#include"../Tree.h"

int leafNodes(TreeNode<int>* root) {
    if(root == NULL) return 0;
    if(root->childrens.size() == 0) return 1;
    int ans{};
    for(int i{}; i < root->childrens.size(); i++) ans += leafNodes(root->childrens[i]);
    return ans;
}

int main(){
    TreeNode<int>* root{takeInputLevelWise()};
    int ans{leafNodes(root)};
    cout << ans << endl;
}
