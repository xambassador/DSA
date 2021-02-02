#include<iostream>
#include<algorithm>
#include<climits>

class Node {
    public:
    int max;
    int secondMax;
};


void buildTree(int* arr, Node* tree, int start, int end, int treeIndex) {

    if(start == end) {
        tree[treeIndex].max = arr[start];
        tree[treeIndex].secondMax = INT_MIN;
        return;
    }

    int mid {(start + end) / 2};
    buildTree(arr,tree,start, mid, 2*treeIndex);
    buildTree(arr,tree,mid+1, end, 2*treeIndex+1);

    Node left {tree[2*treeIndex]};
    Node right {tree[2*treeIndex+1]};
    int maximum {std::max(left.max,right.max)};
    int secondMaximum {std::min(std::max(left.secondMax, right.max), std::max(left.max, right.secondMax))};
    Node pair;
    pair.max = maximum;
    pair.secondMax = secondMaximum;
    tree[treeIndex] = pair;
    return;
}


Node query(Node* tree, int treeIndex, int start, int end, int left, int right) {
    // Completely outside
    if(left > end || right < start) {
        Node ans {INT_MIN, INT_MIN};
        return ans;
    }

    // Completely inside
    if(left <= start && right >= end) return tree[treeIndex];

    // Partially inside
    int mid {(start + end) / 2};
    Node ans1 {query(tree, 2*treeIndex, start, mid, left, right)};
    Node ans2 {query(tree, 2*treeIndex+1, mid+1, end, left, right)};

    Node ans;
    ans.max = std::max(ans1.max, ans2.max);
    ans.secondMax = std::min(std::max(ans1.max, ans2.secondMax), std::max(ans1.secondMax, ans2.max));
    return ans;
}

void update(int* arr, Node* tree, int treeIndex, int start, int end, int index, int value) {
    if(start == end ) {
        tree[treeIndex].max = value;
        tree[treeIndex].secondMax = INT_MIN;
        arr[index] = value;
        return;
    }

    int mid {(start + end) / 2};
    if(index > mid) {
        update(arr,tree,2*treeIndex+1, mid+1, end, index, value);
    } else {
        update(arr, tree, 2*treeIndex, start, mid, index, value);
    }

    Node left = tree[2*treeIndex];
    Node right = tree[2*treeIndex+1];
    tree[treeIndex].max = std::max(left.max, right.max);
    tree[treeIndex].secondMax = std::min(std::max(left.max,right.secondMax), std::max(left.secondMax, right.max));
    return;
}


int main(){
    int n;
    std::cin >> n;
    int* arr {new int[n]};
    for(int i{};i<n; i++) std::cin >> arr[i];
    
    Node* tree {new Node[4*n]};
    buildTree(arr,tree,0,n-1,1);
    int q;
    std::cin >> q;
    while(q--) {
        char c;
        std::cin >> c;
        int left,right;
        std::cin >> left >> right;
        if(c == 'Q') {
            Node ans {query(tree,1,0,n-1,left-1,right-1)};
            std::cout << ans.max+ans.secondMax << std::endl;
        } else if(c == 'U') {
            update(arr,tree,1,0,n-1,left-1,right);
        }
    }   
}