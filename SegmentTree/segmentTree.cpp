#include<iostream>


// Function that Build Segment Tree from array and store it in array
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

    segTree[treeIndex] = segTree[2*treeIndex] + segTree[2*treeIndex + 1];
}


//  Update Tree
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
    segTree[treeIndex] = segTree[2*treeIndex] + segTree[2*treeIndex + 1];
}

// Query in segment tree
int query(int* tree, int start, int end, int treeNode, int left , int right) {
    // case 1 : If range is completely outside
    if(start > right || end < left) return 0;

    // case 2 : If range is completely inside
    if(start >= left && end <= right) return tree[treeNode];

    // case 3 : If range is partially inside and partially outside
    int mid {(start + end) / 2};
    int ans1 {query(tree,start, mid, 2*treeNode, left, right)};
    int ans2 {query(tree,mid+1,end, 2*treeNode+1, left,  right)};
    return ans1 + ans2;
}

int main(){
    // array size
    int n;
    std::cin >> n;

    // Array
    int* arr {new int[n]};
    for(int i{}; i<n; i++) std::cin >> arr[i];

    // segment tree contain 2N nodes
    int* segTree {new int[2*n]};
    
    buildSegTree(arr,segTree,0,n-1,1);

    updateTree(arr,segTree,0,n-1,1,2,10); // arr[2] = 10

    for(int i{1}; i<2*n; i++) std::cout << segTree[i] << std::endl;

    // Query : sum between interval [2,4]
    int ans {query(segTree,0,n-1,1,2,4)};
    std::cout << "Sum between range is : " << ans << std::endl;
}