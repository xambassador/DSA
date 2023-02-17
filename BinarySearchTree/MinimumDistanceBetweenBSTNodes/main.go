package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func minDiffInBST(root *TreeNode) int {
	var minDiff = 100000
	var prev *TreeNode
	var inOrder func(*TreeNode)
	inOrder = func(node *TreeNode) {
		if node == nil {
			return
		}
		inOrder(node.Left)
		if prev != nil {
			minDiff = min(minDiff, node.Val-prev.Val)
		}
		prev = node
		inOrder(node.Right)
	}
	inOrder(root)
	return minDiff
}
