#include<iostream>
using std::cout;
using std::endl;
using std::boolalpha;
#include"../Tree.h"

bool isIdentical(TreeNode<int>* root1, TreeNode<int>* root2) {
    bool ans{false};
    if(root1->data == root2->data) {
        for(int i{}; i < root1->childrens.size(); i++) {
            bool tmpAns{isIdentical(root1->childrens[i], root2->childrens[i])};
            if(tmpAns == false) return false;
            else continue;
        }
        ans = true;
    }
    return ans;
}

int main() {
    TreeNode<int>* root1{takeInputLevelWise()};
    TreeNode<int>* root2{takeInputLevelWise()};
    bool ans{isIdentical(root1, root2)};
    cout << boolalpha << ans << endl;
}
