
class Node :
    maximum = 0
    secondMaximum = float('-inf')



def buildTree(arr,tree,treeIndex,start,end) :
    if start == end : 
        tree[treeIndex].maximum = arr[start]
        return
    
    mid = int((start + end ) / 2)
    buildTree(arr,tree,2*treeIndex,start,mid)
    buildTree(arr,tree,2*treeIndex+1,mid+1,end)

    left = tree[2*treeIndex]
    right = tree[2*treeIndex+1]
    tree[treeIndex].maximum = max(left.maximum, right.maximum)
    tree[treeIndex].secondMaximum = min(max(left.maximum, right.secondMaximum), max(left.secondMaximum, right.maximum))
    return


def query(tree, treeIndex, start, end, left, right) :
    # Completely outside
    if left > end or right < start :
        ans = Node()
        ans.maximum = float('-inf')
        ans.secondMaximum = float('inf')
        return ans
    
    # Completely inside
    if left <= start and right >= end :
        return tree[treeIndex]
    
    # partially inside
    mid = int((start + end) / 2)
    ans1 = query(tree,2*treeIndex, start,mid, left,right)
    ans2 = query(tree, 2*treeIndex+1, mid+1, end, left, right)
    ans = Node()
    ans.maximum = max(ans1.maximum, ans2.maximum)
    ans.secondMaximum = min(max(ans1.maximum, ans2.secondMaximum), max(ans1.secondMaximum, ans2.maximum))
    return ans

def update(arr, tree, treeIndex, start, end, index, value) :
    if start == end : 
        tree[treeIndex].maximum = arr[start]
        tree[treeIndex].secondMaximum = float('-inf')
        arr[start] = value
        return
    
    mid = int((start + end) / 2)
    if index > mid : 
        update(arr, tree, 2*treeIndex+1, mid+1, end, index, value)
    else : 
        update(arr, tree, 2*treeIndex, start, mid, index, value)
    
    left = tree[2*treeIndex]
    right = tree[2*treeIndex+1]
    tree[treeIndex].maximum  =  max(left.maximum, right.maximum)
    tree[treeIndex].secondMaximum = min(max(left.maximum, right.secondMaximum), max(left.secondMaximum, right.maximum))
    return


if __name__ == "__main__" :
    n = int(input())
    arr = list(map(int, input().split()))
    tree = []
    for i in range(0,3*n) :
        tree.append(Node())

    buildTree(arr,tree,1,0,n-1)
    q = int(input())
    while q > 0 : 
        inputs = list(map(str, input().split()))
        c = inputs[0]
        left = int(inputs[1])
        right = int(inputs[2])
        if c == 'Q' : 
            ans = query(tree, 1, 0, n-1, left-1, right-1)
            print(ans.maximum + ans.secondMaximum)
        else : 
            update(arr, tree, 1, 0, n-1, left-1, right)
        
        q = q - 1