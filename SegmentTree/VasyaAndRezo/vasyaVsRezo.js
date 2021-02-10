(function() {

    const Warrior = {
        Ai : undefined,
        Bi : undefined,
    };

    const Node = {
        Ai : undefined,
        Bi : undefined,
        index : undefined
    };

    function build(arr, tree, start, end, treeIndex) {
        if (start === end) {
            tree[treeIndex] = {...Node};
            tree[treeIndex].Ai = arr[start].Ai;
            tree[treeIndex].Bi = arr[start].Bi;
            tree[treeIndex].index = start;
            return;
        }

        let mid = parseInt((start + end) / 2);
        build(arr,tree,start, mid, 2*treeIndex);
        build(arr,tree,mid+1, end, 2*treeIndex+1);

        let left = tree[2*treeIndex];
        let right = tree[2*treeIndex+1];
        tree[treeIndex] = {...Node};
        // Store max Ai warrior
        if (left.Ai > right.Ai) {
            tree[treeIndex].Ai = left.Ai;
            tree[treeIndex].Bi = left.Bi;
            tree[treeIndex].index = left.index;
        } else if (left.Ai < right.Ai) {
            tree[treeIndex].Ai = right.Ai;
            tree[treeIndex].Bi = right.Bi;
            tree[treeIndex].index = right.index;
        } else if (left.Ai === right.Ai) {
            // Store min Bi warrior
            if (left.Bi < right.Bi) {
                tree[treeIndex].Ai = left.Ai;
                tree[treeIndex].Bi = left.Bi;
                tree[treeIndex].index = left.index;
            } else if (left.Bi > right.Bi) {
                tree[treeIndex].Ai = right.Ai;
                tree[treeIndex].Bi = right.Bi;
                tree[treeIndex].index = right.index;
            } else if (left.Bi === right.Bi) {
                // Store first index
                if (left.index < right.index) {
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

    function query(tree, start, end, treeIndex, left, right) {
        // Outside
        if(start > right || end < left) {
            const ans = {...Node};
            ans.Ai = Number.MIN_SAFE_INTEGER;
            ans.Bi = Number.MAX_SAFE_INTEGER;
            ans.index = Number.MAX_SAFE_INTEGER;
            return ans;
        }

        // Inside
        if (start >= left && end <= right) return tree[treeIndex];

        // Partially
        const mid = parseInt((start + end) / 2);
        const leftAns = query(tree, start, mid, 2*treeIndex, left, right);
        const rightAns = query(tree, mid+1, end, 2*treeIndex+1, left, right);

        let ans = {...Node};
        if (leftAns.Ai > rightAns.Ai) {
            ans = leftAns;
        } else if (leftAns.Ai < rightAns.Ai) {
            ans = rightAns;
        } else if (leftAns.Ai === rightAns.Ai) {
            if (leftAns.Bi < rightAns.Bi) {
                ans = leftAns;
            } else if (leftAns.Bi > rightAns.Bi) {
                ans = rightAns;
            } else if (leftAns.Bi === rightAns.Bi) {
                if (leftAns.index < rightAns.index ) {
                    ans = leftAns;
                } else {
                    ans = rightAns;
                }
            }
        }

        return ans;
    }

    (function main() {

        let Ai = [1,8,4,6,8];
        let Bi = [4,8,6,3,7];
        let arr = [];
        for (let i = 0; i<Ai.length; i++) {
            let w = {...Warrior};
            w.Ai = Ai[i];
            w.Bi = Bi[i];
            arr.push(w);
        }

        const n = arr.length;
        const tree = [];
        build(arr,tree,0,n-1,1);

        let q = 0;
        let queries = [
            {li: 1, ri: 4},
            {li: 2, ri: 4},
            {li: 3, ri: 4},
            {li: 1, ri: 5},
        ];
        while(q < queries.length) {
            let {li,ri} = queries[q];
            const ans = query(tree,0,n-1,1,li-1,ri-1);
            console.log(ans.index + 1);
            q++;
        }

    }());


}());