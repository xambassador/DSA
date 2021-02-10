#include<iostream>
#include<climits>

int power[100001];

void buildPower() {
    power[0] = 1;
    for(int i{1}; i<100001; i++) power[i] = (power[i-1]*2) % 3;
}

void build(int* arr, int* tree, int start, int end, int treeIndex) {
    if (start == end ) {
        tree[treeIndex] = arr[start];
        return;
    }

    int mid {(start + end) / 2};
    build(arr, tree, start, mid, 2*treeIndex);
    build(arr, tree, mid+1, end, 2*treeIndex+1);

    int left {tree[2*treeIndex]};
    int right {tree[2*treeIndex+1]};
    tree[treeIndex] = (power[end - mid] * left + right) % 3;
    return;
}


void update(int* arr, int* tree, int start, int end, int treeIndex, int index) {
    if(start == end) {
        arr[index] = 1;
        tree[treeIndex] = 1;
        return;
    }

    int mid {(start + end ) / 2};
    if (index > mid) update(arr, tree, mid+1, end, 2*treeIndex+1, index);
    else update(arr, tree, start, mid, 2*treeIndex, index);

    int left {tree[2*treeIndex]};
    int right {tree[2*treeIndex+1]};
    tree[treeIndex] = (power[end - mid] * left + right) % 3;
    return;
}

int query(int* tree, int start, int end, int treeIndex, int left, int right) {
    if (start > right || end < left) return 0;

    if (start >= left && end <= right) return (tree[treeIndex]*power[right-end]) % 3;

    int mid {(start + end) / 2};
    int leftAns {query(tree, start, mid, 2*treeIndex, left, right)};
    int rightAns {query(tree, mid+1, end, 2*treeIndex + 1, left, right)};
    return (left + right) % 3;
}

int main() {
    buildPower();
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int* arr {new int[n]};
    for(int i{}; i<n; i++) arr[i] = s[i] - '0';

    int* tree {new int[4*n]()};
    build(arr,tree,0,n-1,1);
    int q;
    std::cin >> q;

    while(q--) {
        int qType;
        std::cin >> qType;
        if (qType == 0) {
            int left, right;
            std::cin >> left >> right;
            std::cout << query(tree,0,n-1,1,left,right) << std::endl;
        } else {
            int index;
            std::cin >> index;
            if(arr[index] == 0) {
                update(arr,tree,0,n-1,1,index);
            }
        }
    }
}