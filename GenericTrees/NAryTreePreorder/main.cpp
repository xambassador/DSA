#include <iostream>
#include <vector>
using std::vector;

class Node {
    public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void preorderTraversal(Node* root, vector<int>& preorderArray) {
    if (root == NULL) return;
    preorderArray.push_back(root -> val);
    for (int i{}; i < root -> children.size(); i++) preorderTraversal(root -> children[i], preorderArray);
    return;
}

 vector<int> preorder(Node* root) {
    vector<int> ans;
    preorderTraversal(root, ans);
    return ans;
}
