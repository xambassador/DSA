#include<algorithm>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;
#include"../BinaryTree.h"

int height(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    int _height {height(root->left) + height(root->right)};
    int leftDiameter {diameter(root->left)};
    int rightDiameter {diameter(root->right)};
    return max(_height, max(leftDiameter, rightDiameter));
}

int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    int ans {diameter(root)};
    cout << ans << endl;
}
