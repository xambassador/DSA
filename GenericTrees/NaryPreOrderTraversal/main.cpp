#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------
void preorderTraversal(Node* root, vector<int>& preorderArray) {
    if (root == NULL) return;
    preorderArray.push_back(root -> val);
    for (int i{}; i < root -> children.size(); i++) {
        preorderTraversal(root -> children[i], preorderArray);
    }
    return;
}

// -----------------------------------------------------------------------------
vector<int> preorder(Node* root) {
    vector<int> ans;
    preorderTraversal(root, ans);
    return ans;
}

// -----------------------------------------------------------------------------
int main () {
    Node* root {new Node(1)};
    Node* node1 {new Node(3)};
    Node* node2 {new Node(2)};
    Node* node3 {new Node(4)};
    Node* node4 {new Node(5)};
    Node* node5 {new Node(6)};
    root -> children.push_back(NULL);
    root -> children.push_back(node1);
    root -> children.push_back(node2);
    root -> children.push_back(node3);
    root -> children.push_back(NULL);
    node1 -> children.push_back(node4);
    node1 -> children.push_back(node5);

    vector<int> ans {preorder(root)};
    for (int i{}; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    delete root, node1, node2, node3, node4, node5;
}
