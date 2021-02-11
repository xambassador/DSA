#include<iostream>

typedef long long ll;


void updateAdd(ll* tree, ll* lazy, ll start, ll end, ll treeIndex, ll left, ll right, ll value){
    if(start > end) return;

    if(lazy[treeIndex] != 0) {
        tree[treeIndex] += (end - start + 1) * lazy[treeIndex];
        if(start != end) {
            lazy[2*treeIndex] += lazy[treeIndex];
            lazy[2*treeIndex + 1] += lazy[treeIndex];
        }

        lazy[treeIndex] = 0;
    }

    // Outside
    if(start > right || end < left) return;

    // Inside
    if(start >= left && end <= right) {
        tree[treeIndex] += (end - start + 1) * value;
        if(start != end) {
            lazy[2*treeIndex] += value;
            lazy[2*treeIndex + 1] += value;
        }
        return;
    }

    // Partial
    ll mid {(start + end) / 2};
    updateAdd(tree, lazy, start, mid, 2*treeIndex, left, right, value);
    updateAdd(tree, lazy, mid+1, end, 2*treeIndex+1, left, right, value);
    tree[treeIndex] = tree[2*treeIndex] + tree[2*treeIndex + 1];
    return;
}


ll query(ll* tree, ll* lazy, ll start, ll end, ll treeIndex, ll left, ll right) {
    if(start > end) return 0;

    if(lazy[treeIndex] != 0) {
        tree[treeIndex] +=(end - start + 1) * lazy[treeIndex];
        if(start != end) {
            lazy[2*treeIndex] += lazy[treeIndex];
            lazy[2*treeIndex + 1] += lazy[treeIndex];
        }
        lazy[treeIndex] = 0;
    }

    // Outside
    if (start > right || end < left) return 0;

    if(start >= left && end <= right) return tree[treeIndex];

    ll mid {(start + end) / 2};
    ll leftAns {query(tree, lazy, start, mid, 2*treeIndex, left, right)};
    ll rightAns {query(tree, lazy, mid+1, end, 2*treeIndex+1, left, right)};
    return leftAns + rightAns;
}

int main(){
    ll t;
    std::cin >> t;
    while(t--) {
        ll n,c;
        std::cin >> n >> c;

        ll* tree {new ll[4*n]()};
        ll* lazy {new ll[4*n]()};

        while(c--) {
            ll type;
            std::cin >> type;

            if(type == 0 ) {
                ll left, right, value;
                std::cin >> left >> right >> value;
                updateAdd(tree, lazy,0, n-1, 1, left-1, right-1, value);
            } else {
                ll left, right;
                std::cin >> left >> right;
                std::cout << query(tree, lazy,0, n-1, 1, left-1, right-1) << std::endl;
            }
        }

        delete tree;
        delete lazy;
    }
}