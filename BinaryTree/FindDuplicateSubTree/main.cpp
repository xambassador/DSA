#include <vector>
#include <unordered_map>
#include <string>
using std::vector;
using std::unordered_map;
using std::string;
using std::to_string;

// -----------------------------------------------------------------------------------------
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 int traverse(TreeNode* node, unordered_map<string, int>& tripletId, unordered_map<int, int>& count, vector<TreeNode*>& res) {
    if (!node) return 0;

    int left {traverse(node->left, tripletId, count, res)};
    int right {traverse(node->right, tripletId, count, res)};
    string triplet = to_string(left) + "," + to_string(node->val) + "," + to_string(right);

    if (!tripletId.count(triplet)) tripletId[triplet] = tripletId.size() + 1;

    int id {tripletId[triplet]};
    count[id]++;

    if (count[id] == 2) res.push_back(node);

    return id;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> tripletId;
    unordered_map<int, int> count;
    vector<TreeNode*> res;
    traverse(root, tripletId, count, res);
    return res;
}
