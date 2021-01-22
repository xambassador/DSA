#include<iostream>
#include<algorithm>
#include<climits>

void buildSegTree(int* arr, int* segTree, int start, int end, int treeIndex) {
    
    // Base case
    if(start == end) {
        segTree[treeIndex] = arr[start];
        return;
    }
    
    // Calculate Mid
    int mid {(start+end) / 2};

    // Call recursion to build left subtree
    buildSegTree(arr,segTree,start,mid,2*treeIndex);

    // Call recursion to build right subtree
    buildSegTree(arr,segTree, mid+1,end,2*treeIndex+1);
    segTree[treeIndex] = std::min(segTree[2*treeIndex], segTree[2*treeIndex + 1]);
}

int query(int* segTree,int start, int end, int treeNode, int left, int right) {
    // complete outside
    if(start > right || end < left) return INT_MAX;

    // complete inside
    if(start >= left && end <= right) return segTree[treeNode];

    // partially
    int mid {(start + end) / 2};
    int ans1 {query(segTree,start,mid,2*treeNode,left,right)};
    int ans2 {query(segTree,mid+1,end,2*treeNode+1,left,right)};
    return std::min(ans1,ans2);
}

void updateTree(int* arr, int* segTree, int start, int end, int treeIndex, int index, int newValue) {
    if (start == end) {
        segTree[treeIndex] = newValue;
        arr[index] = newValue;
        return;
    }

    int mid {(start+end) / 2};

    if(index > mid) {
        updateTree(arr,segTree,mid+1,end,2*treeIndex+1,index,newValue);
    } else {
        updateTree(arr,segTree,start,mid,2*treeIndex,index,newValue);
    }

    // Updating tree node
    segTree[treeIndex] = std::min(segTree[2*treeIndex], segTree[2*treeIndex + 1]);
}

int main(){
    int n,q;
    std::cin >> n >> q;
    int arr[n];
    for(int i{}; i<n; i++) std::cin >> arr[i];
    
    int* segTree {new int[4*n]};
    for(int i{}; i<n; i++) segTree[i] = 0;
    buildSegTree(arr,segTree,0,n-1,1);


    while(q--) {
        char c;
        std::cin >> c;
        int left,right;
        std::cin >> left >> right;
        if(c == 'q') {
            int ans {query(segTree,0,n-1,1,left-1,right-1)};
            std::cout << ans << std::endl;
        } else {
            updateTree(arr,segTree,0,n-1,1,left-1,right);
        }
    }
}