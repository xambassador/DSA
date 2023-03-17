#include <queue>
using std::queue;

// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isCompleteTree(TreeNode* root) {
    // If root is nullptr, return true
    if (root == nullptr) return true;
    // Create a queue and push root into it
    queue<TreeNode*> q{{root}};
    // While the front of the queue is not nullptr
    while (q.front() != nullptr) {
        TreeNode* node {q.front()};
        q.pop();
        // Push the left and right child of the node into the queue
        q.push(node->left);
        q.push(node->right);
    }
    // Pop nodes from queue until the front is not nullptr
    while (!q.empty() && q.front() == nullptr) q.pop();
    return q.empty();
}
