#include<iostream>
using namespace std;
#include"../BST.h"

bool isBSTHelp(BinarySearchTreeNode<int>* root, int min, int max){
   if(root == NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    return isBSTHelp(root->left,min,root->data-1) && isBSTHelp(root->right,root->data+1,max);
}

bool isBST_2(BinarySearchTreeNode<int> *root){
    return isBSTHelp(root,INT_MIN,INT_MAX);

}

/* ************************************************************************  */
int Maximum(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return INT_MIN;
    return max(root->data, max(Maximum(root->left), Maximum(root->right)));
}

int Minimum(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return INT_MAX;
    return min(root->data, min(Minimum(root->left), Minimum(root->right)));
}

bool isBST_1(BinarySearchTreeNode<int>* root) {
    if(root == NULL) return true;

    int leftMaximum {Maximum(root->left)};
    int rightMinimum {Minimum(root->right)};
    return (root->data >= leftMaximum) && (root->data <= rightMinimum) && (isBST_1(root->left)) && (isBST_1(root->right));
}
/* ************************************************************************  */


/* ************************************************************************  */

class Pair {
    public:
    int max;
    int min;
    bool isBST;
    bool isLeafNode;
};

Pair help(BinarySearchTreeNode<int>* root) {
    if(root == NULL) {
        Pair ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        ans.isBST = true;
        return ans;
    }

    if(root->left == NULL && root->right == NULL) {
        Pair ans;
        ans.min = root->data;
        ans.max = root->data;
        ans.isBST = true;
        return ans;
    }

    Pair left {help(root->left)};
    Pair right {help(root->right)};

    // int minimum {min(root->data,min(left.min,right.min))};
    // int maximum {max(root->data, max(left.max,right.max))};
    
    bool isBST {root->data >= left.max && root->data <= right.min && left.isBST && right.isBST};
    int minimum {min(root->data,min(left.min,right.min))};
    int maximum {max(root->data,max(left.max,right.max))};

    Pair ans;
    ans.isBST = isBST;
    ans.min = minimum;
    ans.max = maximum;
    return ans;
}


bool isBST(BinarySearchTreeNode<int>* root) {
    Pair ans {help(root)};
    return ans.isBST;
}

/* ************************************************************************  */




int main() {
    BinarySearchTreeNode<int>* root {takeInput()};
    print(root);
    bool ans1 {isBST_1(root)};
    bool ans2 {isBST_2(root)};
    bool ans3 {isBST(root)};
    cout << "using method 1 = " <<  boolalpha << ans1 << endl;
    cout << "using method 2 = " <<  boolalpha << ans2 << endl;
    cout << "using method 3 = " <<  boolalpha << ans3 << endl;
}