#include<iostream>
#include<climits>

class Warriors {
    public:
    int Ai;
    int Bi;
};

class Node {
    public:
    int Ai;
    int Bi;
    int index;
};

void build(Warriors* arr, Node* tree, int start, int end, int treeIndex) {
    if(start == end) {
        tree[treeIndex].Ai = arr[start].Ai;
        tree[treeIndex].Bi = arr[start].Bi;
        tree[treeIndex].index = start;
        return;
    }

    int mid {(start + end) / 2};
    build(arr, tree, start, mid, 2*treeIndex);
    build(arr, tree, mid+1, end, 2*treeIndex+1);
    
    Node left {tree[2*treeIndex]};
    Node right {tree[2*treeIndex+1]};
    // Check for Ai. Store Ai with max value
    if(left.Ai > right.Ai) {
        tree[treeIndex].Ai = left.Ai;
        tree[treeIndex].Bi = left.Bi;
        tree[treeIndex].index = left.index;
    } else if (left.Ai < right.Ai) {
        tree[treeIndex].Ai = right.Ai;
        tree[treeIndex].Bi = right.Bi;
        tree[treeIndex].index = right.index;
    } else if (left.Ai == right.Ai) {
        // Choose minimum Bi
        if(left.Bi < right.Bi) {
            tree[treeIndex].Ai = left.Ai;
            tree[treeIndex].Bi = left.Bi;
            tree[treeIndex].index = left.index;
        } else if (left.Bi > right.Bi) {
            tree[treeIndex].Ai = right.Ai;
            tree[treeIndex].Bi = right.Bi;
            tree[treeIndex].index = right.index;
        } else if (left.Bi == right.Bi) {
            // Choose minimum index or index which come first
            if(left.index < right.index) {
                tree[treeIndex].Ai = left.Ai;
                tree[treeIndex].Bi = left.Bi;
                tree[treeIndex].index = left.index;
            } else {
                tree[treeIndex].Ai = right.Ai;
                tree[treeIndex].Bi = right.Bi;
                tree[treeIndex].index = right.index;
            }
        }
    }
    return;
}


Node query(Node* tree, int start, int end, int treeIndex ,int left, int right) {
    // Completely outside
    if(start > right || end < left) return {INT_MIN, INT_MAX, INT_MAX};

    // Completely inside
    if(start >= left && end <= right) return tree[treeIndex];

    // Partially

    int mid {(start + end) / 2};
    Node leftAns {query(tree, start, mid, 2*treeIndex, left, right)};
    Node rightAns {query(tree, mid+1, end, 2*treeIndex+1, left, right)};

    Node ans;

    if(leftAns.Ai > rightAns.Ai) {
        ans = leftAns;
    } else if (leftAns.Ai < rightAns.Ai) {
        ans = rightAns;
    } else if (leftAns.Ai == rightAns.Ai) {
        if (leftAns.Bi < rightAns.Bi) {
            ans = leftAns;
        } else if (leftAns.Bi > rightAns.Bi) {
            ans = rightAns;
        } else if (leftAns.Bi == rightAns.Bi) {
            if(leftAns.index < rightAns.index) {
                ans = leftAns;
            } else {
                ans = rightAns;
            }
        }
    }
    return ans;
}


int main(){
    int n;
    std::cin >> n;
    Warriors* arr {new Warriors[n]};
    for(int i{}; i<n; i++) std::cin >> arr[i].Ai;
    for(int i{}; i<n; i++) std::cin >> arr[i].Bi;

    // Segment tree
    Node* tree {new Node[4*n]()};
    build(arr,tree,0,n-1,1);

    int Q;
    std::cin >> Q;
    while(Q--) {
        int li, ri;
        std::cin >> li >> ri;
        Node ans {query(tree, 0, n-1, 1, li-1, ri-1)};
        std::cout << (ans.index)+1 << std::endl;
    }
    return 0;
}