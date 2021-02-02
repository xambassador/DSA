(function () {
    

    function buildTree(arr,tree,treeIndex,start,end) {
        if(start === end) {
            tree[treeIndex].max = arr[start];
            tree[treeIndex].secondMax = Number.MIN_SAFE_INTEGER;
            return;
        }

        let mid = parseInt((start + end) / 2);
        buildTree(arr,tree,2*treeIndex,start,mid);
        buildTree(arr,tree,2*treeIndex+1, mid+1, end);

        let left = tree[2*treeIndex];
        let right = tree[2*treeIndex+1];
        tree[treeIndex].max = Math.max(left.max, right.max);
        tree[treeIndex].secondMax = Math.min(Math.max(left.max, right.secondMax), Math.max(left.secondMax, right.max));
        return;  
    }

    function query(tree, treeIndex, start, end, left, right) {
        // Completely outside
        if(left > end || right < start) {
            let obj = {};
            obj.max = Number.MIN_SAFE_INTEGER;
            obj.secondMax = Number.MIN_SAFE_INTEGER;
            return obj;
        }

        // completely inside
        if(left <= start && right >= end) return tree[treeIndex];

        // partially inside
        let mid = parseInt((start + end) / 2);
        let ans1 = query(tree, 2*treeIndex, start, mid, left, right);
        let ans2 = query(tree, 2*treeIndex+1, mid+1, end, left, right);
        let ans = {};
        ans.max = Math.max(ans1.max,ans2.max);
        ans.secondMax = Math.min(Math.max(ans1.max, ans2.secondMax), Math.max(ans1.secondMax,ans2.max));
        return ans;
    }

    function update(arr,tree,treeIndex,start,end,index,value) {
        if(start === end) {
            tree[treeIndex].max = value;
            tree[treeIndex].secondMax = Number.MIN_SAFE_INTEGER;
            arr[start] = value;
            return;
        }

        let mid = parseInt((start + end) / 2);
        if(index > mid) update(arr,tree,2*treeIndex+1,mid+1,end,index,value);
        else update(arr,tree,2*treeIndex,start,mid,index,value);

        let left = tree[2*treeIndex];
        let right = tree[2*treeIndex+1];
        tree[treeIndex].max = Math.max(left.max, right.max);
        tree[treeIndex].secondMax = Math.min(Math.max(left.max,right.secondMax), Math.max(left.secondMax,right.max));
        return;
    }

    (function main(){

        let arr = [1,2,3,4,5];
        let n = arr.length;
        let tree = [];
        for(let i=0; i<3*n; i++) {
            tree[i] = {};
            tree[i].max = Number.MIN_SAFE_INTEGER;
            tree[i].secondMax = Number.MIN_SAFE_INTEGER;
        }
        buildTree(arr,tree,1,0,n-1);
        
        let queries = [
            {query:"Q",range:{left:2,right:4}},
            {query:"Q",range:{left:2,right:5}},
            {query:"U",range:{left:1,right:6}},
            {query:"Q",range:{left:1,right:5}},
            {query:"U",range:{left:1,right:7}},
            {query:"Q",range:{left:1,right:5}},
        ];

        for(i of queries) {
            if(i.query === "Q") {
                let ans = query(tree,1,0,n-1,i.range.left-1, i.range.right-1);
                console.log(ans.max + ans.secondMax);
            } else {
                update(arr,tree,1,0,n-1,i.range.left-1,i.range.right);
            }
        }
    })();
})();