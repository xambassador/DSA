#pragma once
#include<vector>
using std::vector;
template<typename T>
class TreeNode {
    public:
    T data; // Data that store in tree
    vector<TreeNode<T>*> childrens; // vector for store child nodes address

    // Default constructor
    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for(int i{}; i<childrens.size(); i++) delete childrens[i];
    }
};
