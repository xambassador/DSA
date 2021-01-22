(function(){


    function buildSegTree(arr,segTree, start, end, treeIndex) {
        // Base case
        if(start === end) {
            segTree[treeIndex] = arr[start];
            return;
        }

        let mid = parseInt((start+end) / 2);
        buildSegTree(arr,segTree,start,mid,2*treeIndex); // build left subtree
        buildSegTree(arr,segTree,mid+1,end,2*treeIndex+1); //  build right subtree

        // calculate our answer
        segTree[treeIndex] = segTree[2*treeIndex] + segTree[2*treeIndex+1];
    }

    // Update tree
    function updateTree(arr,segTree,start,end,treeIndex,index, newValue) {
        if(start === end) {
            arr[index] = newValue;
            segTree[treeIndex] = newValue;
            return;
        }

        let mid = parseInt((start+end) / 2);

        if(index > mid) {
            updateTree(arr,segTree,mid+1,end,2*treeIndex+1,index,newValue);
        } else {
            updateTree(arr,segTree,start,mid,2*treeIndex,index, newValue);
        }

        segTree[treeIndex] = segTree[2*treeIndex] + segTree[2*treeIndex + 1];
    }

    // Query in Segment tree
    function query(tree,start,end,treeNode,left, right) {
        // case 1 : completely outside
        if(start > right || end < left) return 0;
        
        // case 2 : completely inside
        if(start >= left && end <= right) return tree[treeNode];

        // case 3 : partially inside and partially outside
        let mid = (start + end) / 2;
        let ans1 = query(tree,start,mid,2*treeNode,left,right);
        let ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);
        return ans1+ans2;
    }


    (function main(){

        // let arr = [1,2,3,4,5,6,7,8,9];
        let arr = [1,2,3,4,5];
        let n = arr.length;
        
        // Segment tree array
        let segTree = new Array(2*n);

        buildSegTree(arr,segTree,0,n-1,1);

        updateTree(arr,segTree,0,n-1,1,2,10); 
        console.log(segTree);

        // Query : sum in range [2,4];
        let ans = query(segTree,0,n-1,1,2,4);
        console.log("Sum in range : ", ans);
    }());
}());