#include<iostream>
using std::cout;
using std::endl;
using std::boolalpha;
#include"../Tree.h"

bool findX(TreeNode<int>* root, int x) {
    if(root == NULL) return false;
    if(root->data == x) return true;
    bool ans{false};
    for(int i{}; i < root->childrens.size(); i++) {
        ans  = findX(root->childrens[i], x);
        if(ans == false) continue;
        else break;
    }
    return ans;
}

int main() {
    int x;
    cin >> x;
    TreeNode<int>* root{takeInputLevelWise()};
    bool ans{findX(root, x)};
    cout << boolalpha << ans << endl;
}
