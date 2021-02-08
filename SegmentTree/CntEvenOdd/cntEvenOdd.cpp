#include<iostream>

class Node {
    public:
    int even;
    int odd;
};


void build(int* arr, Node* tree, int start, int end, int treeIndex) {
    if(start == end) {
        if(arr[start] % 2 == 0) {
            tree[treeIndex].even = 1;
            tree[treeIndex].odd = 0;
        } else {
            tree[treeIndex].odd = 1;
            tree[treeIndex].even = 0;
        }
        return;
    } 

    int mid {(start + end) / 2};
    build(arr,tree,start,mid,2*treeIndex);
    build(arr,tree,mid+1,end,2*treeIndex + 1);
    
    Node left {tree[2*treeIndex]};
    Node right {tree[2*treeIndex + 1]};

    tree[treeIndex].even = left.even + right.even;
    tree[treeIndex].odd = left.odd + right.odd;
    return;
}

void update(int* arr, Node* tree, int start, int end, int treeIndex, int index, int value) {
    if(start == end) {
        arr[index] = value;
        if(value % 2 == 0) {
            tree[treeIndex].even = 1;
            tree[treeIndex].odd = 0;
        } else {
            tree[treeIndex].even = 0;
            tree[treeIndex].odd = 1;
        }
        return;
    }

    int mid {(start + end) / 2};
    if(index > mid) {
        update(arr,tree,mid+1,end,2*treeIndex+1,index,value);
    } else {
        update(arr,tree,start,mid,2*treeIndex,index,value);
    }

    tree[treeIndex].even = tree[2*treeIndex].even + tree[2*treeIndex+1].even;
    tree[treeIndex].odd = tree[2*treeIndex].odd + tree[2*treeIndex+1].odd;
    return;
}

Node query(Node* tree, int start, int end, int treeIndex, int left, int right) {
    if(start > right || end < left) return {0,0};

    if(start >= left && end <= right) return tree[treeIndex];

    int mid {(start + end) / 2};
    Node leftAns {query(tree, start, mid, 2*treeIndex,left,right)};
    Node rightAns {query(tree,mid+1,end,2*treeIndex+1,left,right)};

    Node ans;
    ans.even = leftAns.even + rightAns.even;
    ans.odd = leftAns.odd + rightAns.odd;
    return ans;
}


int main(){
    int n;
    std::cin >> n;
    int* arr {new int[n]};
    for(int i{}; i<n; i++) std::cin >> arr[i];

    Node* tree {new Node[4*n]()};
    build(arr,tree,0,n-1,1);

    int q;
    std::cin >> q;
    while(q--) {
        int queryNum, left, right;
        std::cin >> queryNum >> left >> right;

        if(queryNum == 0) {
            update(arr,tree,0,n-1,1,left-1,right);
        } else {
            Node ans {query(tree,0,n-1,1,left-1,right-1)};
            if (queryNum == 1) std::cout << ans.even << std::endl;
            else std::cout << ans.odd << std::endl;
        }
    }
}