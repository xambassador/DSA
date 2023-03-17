#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void helper(TreeNode* root, int nextNumber, int* sum) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        *sum += root->val + nextNumber;
        return;
    }

    helper(root->left, (nextNumber + root->val) * 10, sum);
    helper(root->right, (nextNumber + root->val) * 10, sum);
}

int sumNumbers(TreeNode* root) {
    int sum {0};
    helper(root, 0, &sum);
    return sum;
}
