#include<vector>
template<typename T>
class TreeNode{
    public:
    T data; // Data that store in tree
    std::vector<TreeNode<T>*> childrens; // vector for store child nodes address

    // Default constructor
    TreeNode(T data){
        this->data = data;
    }
};