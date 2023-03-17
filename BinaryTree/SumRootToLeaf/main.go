package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(root *TreeNode, nextNumber int, sum *int) {
	if root == nil {
		return
	}

	// If node is leaf. We have one number from root to leaf.
	if root.Left == nil && root.Right == nil {
		*sum += root.Val + nextNumber
		return
	}

	// Node is not leaf
	helper(root.Left, (nextNumber+root.Val)*10, sum)
	helper(root.Right, (nextNumber+root.Val)*10, sum)
}

func sumNumbers(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var sum int = 0
	helper(root, 0, &sum)
	return sum
}
