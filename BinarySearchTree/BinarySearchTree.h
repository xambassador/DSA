template<typename T>
class BinarySearchTreeNode {
    public:
    T data;
    BinarySearchTreeNode<T>* left;
    BinarySearchTreeNode<T>* right;
    BinarySearchTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinarySearchTreeNode(){
        if(left) delete left;
        if(right) delete right;
    }
};