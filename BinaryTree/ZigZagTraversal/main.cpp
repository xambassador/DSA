#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using std::stack;
using std::queue;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, int level, vector<vector<int>>& result) {
    if (root == NULL) return;

    if (level == result.size()) {
        result.push_back({});
    }

    // If level is even
    if (level % 2 == 0) {
        result[level].push_back(root->val);
    } else {
        result[level].insert(result[level].begin(), root->val);
    }

    helper(root->left, level + 1, result);
    helper(root->right, level + 1, result);
}

// Using recursion
vector<vector<int>> zigzagLevelOrderUsingRecursion(TreeNode* root) {
    vector<vector<int>> result;
    helper(root, 0, result);
    return result;
}

// Using two stacks
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) return {};
    vector<vector<int>> result;
    // stack1: Right to left
    // stack2: Left to right
    stack<TreeNode*> stack1, stack2;
    // Push root into stack1
    stack1.push(root);

    // While stack1 is not empty
    while(!stack1.empty()) {
        // Process stack1
        vector<int> temp;
        while(!stack1.empty()) {
            TreeNode* top {stack1.top()};
            temp.push_back(top->val);
            stack1.pop();
            if (top->left != NULL) {
                stack2.push(top->left);
            }
            if (top->right != NULL) {
                stack2.push(top->right);
            }
        }

        // Push temp into result
         if (!temp.empty()) {
            result.push_back(temp);
            temp.clear();
        }

        // Process stack2
        while(!stack2.empty()) {
            TreeNode* top {stack2.top()};
            temp.push_back(top->val);
            stack2.pop();
            if (top->right != NULL) {
                stack1.push(top->right);
            }
            if (top->left != NULL) {
                stack1.push(top->left);
            }
        }

        // Push temp into result
        if (!temp.empty()) {
            result.push_back(temp);
            temp.clear();
        }
    }

    return result;
}


int main () {
    TreeNode* root {new TreeNode(3)};
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // vector<vector<int>> result {zigzagLevelOrder(root)};
    vector<vector<int>> result {zigzagLevelOrderUsingRecursion(root)};
    for (auto& v : result) {
        for (auto& i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
