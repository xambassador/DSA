#include"../BinarySearchTree.h"

class BST {
    BinarySearchTreeNode<int>* root;
    public:
    BST() : root(NULL) {}
    ~BST() {
        delete root;
    }

    private:
    bool search(BinarySearchTreeNode<int>* root, int data) {
        if(root == NULL) return false;

        if(root->data == data) return true;

        if(data < root->data) return search(root->left,data);

        if(data > root->data) return search(root->right,data);
    }

    public:
    bool search(int data) {
        return search(root, data);
    }

    private:
    BinarySearchTreeNode<int>* insert(BinarySearchTreeNode<int>* root, int data) {
        if(root == NULL) {
            BinarySearchTreeNode<int>* node {new BinarySearchTreeNode<int>(data)};
            return node;
        }

        if(data < root->data) {
            BinarySearchTreeNode<int>* left {insert(root->left,data)};
            root->left = left;
            return root;
        }

        if(data > root->data) {
            BinarySearchTreeNode<int>* right {insert(root->right, data)};
            root->right = right;
            return root;
        }
    }

    public:
    void insert(int data) {
        root = insert(root,data);
    }

    private:

    int maximum(BinarySearchTreeNode<int>* root) {
        if(root == NULL) return INT_MIN;

        int left {maximum(root->left)};
        int right {maximum(root->right)};

        return max(root->data, max(left,right));
    }


    BinarySearchTreeNode<int>* remove(BinarySearchTreeNode<int>* root, int data) {
        if(root == NULL) return NULL;

        if(data < root->data) {
            BinarySearchTreeNode<int>* left {remove(root->left,data)};
            root->left = left;
            return root;
        }

        if(data > root->data) {
            BinarySearchTreeNode<int>* right {remove(root->right,data)};
            root->right = right;
            return root;
        }

        if(data == root->data) {
            // leaf node
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // one child
            if(root->left != NULL && root->right == NULL) {
                BinarySearchTreeNode<int>* tmp {root->left};
                delete root;
                return tmp;
            }else if(root->left == NULL && root->right != NULL){
                BinarySearchTreeNode<int>* tmp {root->right};
                delete root;
                return tmp;
            }else{
                int lmax {maximum(root->left)};
                root->data = lmax;
                BinarySearchTreeNode<int>* lans {remove(root->left,lmax)};
                root->left = lans;
                return root;
            }
        }
    }

    public:

    void remove(int data) {
        root = remove(root, data);
    }


    private:

    void print(BinarySearchTreeNode<int>* root) {
        if(root == NULL) return;

        cout << root->data << " : ";
        if(root->left != NULL) cout << "L " << root->left->data << " ,";
        else cout << "L -1 ,";

        if(root->right != NULL) cout << "R " << root->right->data << endl;
        else cout << "R -1" << endl;

        print(root->left);
        print(root->right);
    }

    public:

    void print() {
        print(root);
    }
};
