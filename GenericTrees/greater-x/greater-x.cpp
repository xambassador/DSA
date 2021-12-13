#include<iostream>
using std::cout;
using std::endl;
#include"../Tree.h"

int greaterX(TreeNode<int>* root, int x) {
    if(root == NULL) return 0;
    int ans{};
    for(int i{}; i < root->childrens.size(); i++) ans += greaterX(root->childrens[i], x);
    if(root->data > x) ans += 1;
    return ans;
}

int main() {
    TreeNode<int>* root{takeInputLevelWise()};
    int x;
    cin >> x;
    int ans{greaterX(root, x)};
    cout << ans << endl;
}
