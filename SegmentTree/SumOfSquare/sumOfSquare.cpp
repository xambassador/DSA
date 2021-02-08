#include<iostream>

class treeAttrs {
    public:
    int sum_of_square;
    int sum;
};

class lazyAttrs {
    public:
    int setter = 0;
    int incrementor = 0;
};

void build(int* arr, treeAttrs* tree, int start, int end, int treeIndex) {
    if(start == end) {
        tree[treeIndex].sum_of_square = arr[start]*arr[start];
        tree[treeIndex].sum = arr[start];
        return;
    }

    int mid {(start + end) / 2};
    build(arr,tree,start,mid, 2*treeIndex);
    build(arr,tree,mid+1,end, 2*treeIndex+1);
    tree[treeIndex].sum = tree[2*treeIndex].sum + tree[2*treeIndex+1].sum;
    tree[treeIndex].sum_of_square = tree[2*treeIndex].sum_of_square + tree[2*treeIndex+1].sum_of_square;
    return;
}

void lazyUpdateSetter(treeAttrs* tree, lazyAttrs* lazy, int start, int end, int left, int right, int currentPosition, int x){
    if(start > end) return;

    if(lazy[currentPosition].setter != 0) {
        tree[currentPosition].sum = (right-left+1) * (lazy[currentPosition].setter);
        tree[currentPosition].sum_of_square = (right-left+1) * (lazy[currentPosition].setter * lazy[currentPosition].setter);

        if(start != end) {
            lazy[2*currentPosition].setter = lazy[currentPosition].setter;
            lazy[2*currentPosition + 1].setter = lazy[currentPosition].setter;
        }

        lazy[currentPosition].setter = 0;
    }

    if(start > right || end < left) return;

    if(start >= left && end <= right) {
        tree[currentPosition].sum_of_square = (right - left + 1) * (x * x);
        tree[currentPosition].sum = (right - left + 1) * x;
        if(start != end) {
            lazy[2*currentPosition].setter = x;
            lazy[2*currentPosition + 1].setter = x;
        }
        return;
    }

    int mid {(start + end) / 2};

    lazyUpdateSetter(tree,lazy,start,mid,left,right,2*currentPosition,x);
    lazyUpdateSetter(tree,lazy,mid+1,end,left,right,2*currentPosition+1,x);
    tree[currentPosition].sum = tree[2*currentPosition].sum + tree[2*currentPosition+1].sum;
    tree[currentPosition].sum_of_square = tree[2*currentPosition].sum_of_square + tree[2*currentPosition+1].sum_of_square;
    return;
}

void lazyUpdateIncrement(treeAttrs* tree, lazyAttrs* lazy, int start, int end, int left, int right, int currentPosition, int increment){
    if(start > end) return;
    
    if(lazy[currentPosition].incrementor != 0) {
        tree[currentPosition].sum_of_square += (right - left + 1) * (lazy[currentPosition].incrementor * lazy[currentPosition].incrementor) + 2 * lazy[currentPosition].incrementor * tree[currentPosition].sum;
        tree[currentPosition].sum += (right - left + 1) * lazy[currentPosition].incrementor;
        if (start != end) {
            lazy[2 * currentPosition].incrementor += lazy[currentPosition].incrementor;
            lazy[2 * currentPosition + 1].incrementor += lazy[currentPosition].incrementor;
        }
        lazy[currentPosition].incrementor = 0;
    }

    if(lazy[currentPosition].setter != 0) {
        tree[currentPosition].sum = (right - left + 1) * (lazy[currentPosition].setter);
        tree[currentPosition].sum_of_square = (right - left + 1) * (lazy[currentPosition].setter * lazy[currentPosition].setter);
        if (start != end) {
            lazy[2*currentPosition].setter = lazy[currentPosition].setter;
            lazy[2*currentPosition + 1].setter = lazy[currentPosition].setter;
        }

        lazy[currentPosition].setter = 0;
    }

    if (start > right || end < left) return;

    if (start >= left && end <= right) {
        tree[currentPosition].sum_of_square += (right - left + 1) * (increment * increment) + 2 * increment * tree[currentPosition].sum;
        tree[currentPosition].sum += (right - left + 1) * increment;
        if (start != end) {
            lazy[2*currentPosition].incrementor += increment;
            lazy[2*currentPosition + 1].incrementor += increment;
        }
        return;
    }

    int mid {(start + end) / 2};
    lazyUpdateIncrement(tree, lazy, start, mid, left, right, 2*currentPosition, increment);
    lazyUpdateIncrement(tree, lazy, mid+1, end, left, right, 2*currentPosition + 1, increment);
    tree[currentPosition].sum = tree[2*currentPosition].sum + tree[2*currentPosition+1].sum;
    tree[currentPosition].sum_of_square = tree[2*currentPosition].sum_of_square + tree[2*currentPosition+1].sum_of_square;
    return;
}

treeAttrs query(treeAttrs* tree, lazyAttrs* lazy, int start, int end, int left, int right, int treeIndex) {
    if (start > end ) return {0,0};
    
    if(lazy[treeIndex].incrementor != 0) {
        tree[treeIndex].sum_of_square += 2*lazy[treeIndex].incrementor * tree[treeIndex].sum + lazy[treeIndex].incrementor * lazy[treeIndex].incrementor * (right - left + 1);
        tree[treeIndex].sum += (right - left + 1) * lazy[treeIndex].incrementor;
        if(start != end) {
            lazy[2*treeIndex].incrementor = lazy[treeIndex].incrementor;
            lazy[2*treeIndex + 1].incrementor = lazy[treeIndex].incrementor;
        }
        lazy[treeIndex].incrementor = 0;
    }

    if(lazy[treeIndex].setter != 0) {
        tree[treeIndex].sum = (right - left + 1) * lazy[treeIndex].setter;
        tree[treeIndex].sum_of_square = (right - left + 1) * lazy[treeIndex].setter;
        if(start != end) {
            lazy[2*treeIndex].setter = lazy[treeIndex].setter;
            lazy[2*treeIndex + 1].setter = lazy[treeIndex].setter;
        }
        lazy[treeIndex].setter = 0;
    }

    if(start > right || end < left) return {0,0};

    if(start >= left && end <= right) return tree[treeIndex];

    int mid {(start + end) / 2};

    treeAttrs leftAns {query(tree, lazy, start, mid, left, right, 2*treeIndex)};
    treeAttrs rightAns {query(tree, lazy, mid+1, end, left, right, 2*treeIndex+1)};
    treeAttrs ans;
    ans.sum = leftAns.sum + rightAns.sum;
    ans.sum_of_square = leftAns.sum_of_square + rightAns.sum_of_square;
    return ans;
}


int main() {
    int t;
    std::cin >> t;
    int caseNumber = 1;
    while(t--) {
        std::cout << "Case " << caseNumber << ":" << std::endl;
        int n,q;
        std::cin >> n >> q;
        int* arr {new int[n]};
        for(int i{}; i<n; i++) std::cin >> arr[i];
        treeAttrs* tree {new treeAttrs[4*n]()};
        lazyAttrs* lazy {new lazyAttrs[4*n]()};
        build(arr,tree,0,n-1,1);
        while(q--) {
            int operationType;
            std::cin >> operationType;

            if(operationType == 2) {
                int left, right;
                std::cin >> left >> right;
                std::cout << query(tree,lazy,0,n-1,left-1,right-1,1).sum_of_square << std::endl;
            } else if(operationType == 1) {
                int left, right;
                std::cin >> left >> right;
                int increment;
                std::cin >> increment;
                lazyUpdateIncrement(tree, lazy, 0, n-1, left-1, right-1, 1, increment);
            } else {
                int left, right;
                std::cin >> left >> right;
                int x;
                std::cin >> x;
                lazyUpdateSetter(tree, lazy, 0, n-1, left-1, right-1, 1, x);
            }
        }
        caseNumber++;
    }
}