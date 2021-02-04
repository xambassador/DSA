#include<iostream>
#include<algorithm>
#include<climits>

class Node {
    public:
    int sum;
    int maxSum;
    int bestPrefixSum;
    int bestSuffixSum;
};

void buildTree(int* arr, Node* tree, int start, int end, int treeNode) {
    if(start == end) {
        tree[treeNode].sum = arr[start];
        tree[treeNode].maxSum = arr[start];
        tree[treeNode].bestPrefixSum = arr[start];
        tree[treeNode].bestSuffixSum = arr[start];
        return;
    }

    int mid {(start + end) / 2};
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    Node left {tree[2*treeNode]};
    Node right {tree[2*treeNode + 1]};
    
    tree[treeNode].sum = left.sum + right.sum;
    tree[treeNode].bestPrefixSum = std::max(left.bestPrefixSum, left.sum + right.bestPrefixSum);
    tree[treeNode].bestSuffixSum = std::max(right.bestSuffixSum, right.sum + left.bestSuffixSum);
    tree[treeNode].maxSum = std::max(left.maxSum, std::max(right.maxSum, std::max(left.sum + right.bestPrefixSum, std::max(right.sum + left.bestSuffixSum, left.bestSuffixSum + right.bestPrefixSum))));
    return;
}

Node query(Node* tree, int start, int end, int treeNode, int left, int right) {
    if (start > right || end < left) return {INT_MIN, INT_MIN,INT_MIN,INT_MIN};

    if (start >= left && end <= right) return tree[treeNode];

    int mid {(start + end) / 2};
    Node ans1 {query(tree, start, mid, 2*treeNode, left, right)};
    Node ans2 {query(tree, mid+1, end, 2*treeNode+1, left, right)};

    Node ans;
    ans.sum = ans1.sum + ans2.sum;
    ans.bestPrefixSum = std::max(ans1.bestPrefixSum, ans1.sum + ans2.bestPrefixSum);
    ans.bestSuffixSum = std::max(ans2.bestSuffixSum, ans2.sum + ans1.bestSuffixSum);
    ans.maxSum = std::max(ans1.maxSum, std::max(ans2.maxSum, std::max(ans1.sum + ans2.bestPrefixSum, std::max(ans2.sum + ans1.bestSuffixSum, ans1.bestSuffixSum + ans2.bestPrefixSum))));
    return ans; 
}