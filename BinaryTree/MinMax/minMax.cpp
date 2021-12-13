#include<iostream>
#include<climits>
using std::cout;
using std::endl;
#include"../BinaryTree.h"

class Pair {
    public:
    int min;
    int max;
};

Pair minMax(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair ans;
        ans.max = 0;
        ans.min = INT_MAX;
        return ans;
    }

    Pair leftAns {minMax(root->left)};
    Pair rightAns {minMax(root->right)};

    int max {0}, min{INT_MAX};
    if(leftAns.max > rightAns.max) max = leftAns.max;
    else max = rightAns.max;

    if(leftAns.min < rightAns.min) min = leftAns.min;
    else min = rightAns.min;

    if(root->data > max) max = root->data;
    if(root->data < min) min = root->data;

    Pair ans;
    ans.max = max;
    ans.min = min;
    return ans;
}

int main() {
    BinaryTreeNode<int>* root {TakeInputLevelWise()};
    Pair ans {minMax(root)};
    cout << ans.max << " " << ans.min << endl;
}
