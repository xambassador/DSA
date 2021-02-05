#include<iostream>
#include<algorithm>
#include<climits>

void buildTree(int* arr, int* tree, int start, int end, int treeIndex) {
    if(start == end) {
        tree[treeIndex] = arr[start];
        return;
    }

    int mid {(start + end) / 2};
    buildTree(arr,tree,start,mid,2*treeIndex);
    buildTree(arr,tree,mid+1,end,2*treeIndex+1);

    tree[treeIndex] =  std::min(tree[2*treeIndex], tree[2*treeIndex+1]);
    return;
}


void lazyPropagation(int* tree, int* lazy, int low, int high, int startR, int endR, int currPos, int increment) {
    if(low > high) return;

    if(lazy[currPos] != 0) {
        tree[currPos] += lazy[currPos];

        if(low!=high){
            lazy[2*currPos] += lazy[currPos];
            lazy[2*currPos+1] += lazy[currPos];
        }

        lazy[currPos] = 0;
    }

    // No overlap
    if(startR > high || endR < low) return;

    // Complete overlap 
    if(startR <= low && high <= endR) {
        tree[currPos] += increment;
        if(low != high) {
            lazy[2*currPos] += increment;
            lazy[2*currPos + 1] += increment;
        }
        return;
    }

    // Partial overlap
    int mid {(low + high) / 2};
    lazyPropagation(tree,lazy,low,mid,startR,endR,currPos,increment);
    lazyPropagation(tree,lazy,mid+1,high,startR,endR,currPos,increment);
    tree[currPos] = std::min(tree[2*currPos], tree[2*currPos+1]);
}


int main(){
    int arr[]{1,3,-2,4};
    int* tree {new int[12]()};
    int* lazy {new int[12]()};
    buildTree(arr,tree,0,3,1);
    lazyPropagation(tree,lazy,0,3,0,3,1,3);
    lazyPropagation(tree,lazy,0,3,0,1,1,2);

    std::cout << "Segment tree : " << std::endl;
    for(int i{1}; i<12;i++) {
        std::cout << tree[i] << std::endl;
    }

    std::cout << "Lazy tree : " << std::endl;
    for(int i{1}; i<12; i++) {
        std::cout << lazy[i] << std::endl;
    }

    delete tree;
    delete lazy;
}