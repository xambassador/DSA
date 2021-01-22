(function(){


    function buildTree(arr, segTree, start, end, treeNode) {
        if(start === end) {
            segTree[treeNode] = arr[start];
            return;
        }

        let mid = parseInt((start + end) / 2);
        buildTree(arr,segTree,start,mid, 2*treeNode);
        buildTree(arr,segTree,mid+1,end,2*treeNode+1);
        segTree[treeNode] = Math.min(segTree[2*treeNode], segTree[2*treeNode+1]);
    }

    function update(arr,segTree,start,end,treeNode,index, newValue) {
        if (start === end) {
            segTree[treeNode] = newValue;
            arr[index] = newValue;
            return;
        }

        let mid = parseInt((start+mid) / 2);
        if(index > mid) update(arr,segTree,mid+1,end,2*treeNode+1,index,newValue);
        else update(arr,segTree,start,mid,2*treeNode,index,newValue);
        
        segTree[treeNode] = Math.min(segTree[2*treeNode], segTree[2*treeNode+1]);
    }

    function query(segTree,start,end,treeNode,left,right) {
        if(start > right || end < left) return Number.MAX_SAFE_INTEGER;

        if(start >= left && end <= right) return segTree[treeNode];

        let mid = parseInt((start + end) / 2);
        let ans1 = query(segTree,start,mid,2*treeNode,left,right);
        let ans2 = query(segTree,mid+1,end,2*treeNode+1,left,right);
        return Math.min(ans1,ans2);
    }

    (function main(){
        
        let arr = [1,5,2,4,3];
        let n = 5;

        let segTree = [];
        buildTree(arr,segTree,0,n-1,1);

        let ans = query(segTree,0,n-1,1,0,3);
        console.log(ans);
        console.log(query(segTree,0,n-1,1,2,4));
    }());


}());