package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	if root.Left == nil && root.Right == nil {
		return root
	}

	invertedLeftRoot := invertTree(root.Left)
	invertedRightRoot := invertTree(root.Right)

	root.Left = invertedRightRoot
	root.Right = invertedLeftRoot

	return root
}
