#include<iostream>
using namespace std;
#include"../BinaryTree.h"

class Pair {
    public:
    int height;
    int diameter;
};

Pair help(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair ans;
        ans.height = 0;
        ans.diameter = 0;
        return ans;
    }

    if(root->left == NULL && root->right == NULL) {
        Pair ans;
        ans.height = 1;
        ans.diameter = 0;
        return ans;
    }

    Pair leftAns {help(root->left)};
    Pair rightAns {help(root->right)};

    int leftHeight {leftAns.height};
    int rightHeight {rightAns.height};
    int leftDiameter {leftAns.diameter};
    int rightDiameter {rightAns.diameter};

    int height {1 + max(leftHeight, rightHeight)};
    int diameter {max(leftHeight + rightHeight, max(leftDiameter, rightDiameter))};
    
    Pair ans;
    ans.height = height;
    ans.diameter = diameter;

    return ans;
}

int diameter(BinaryTreeNode<int>* root) {
    return help(root).diameter;
}

int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    int ans {diameter(root)};
    cout << ans << endl;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1