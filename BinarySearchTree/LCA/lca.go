package main

// -----------------------------------------------------------------------------

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// -----------------------------------------------------------------------------

func help(root *TreeNode, p, q int) *TreeNode {
	if root == nil {
		return nil
	}

	if root.Val == p || root.Val == q {
		return root
	}

	left := help(root.Left, p, q)
	right := help(root.Right, p, q)

	if left != nil && right == nil {
		return left
	} else if left == nil && right != nil {
		return right
	} else if left != nil && right != nil {
		return root
	} else if left == nil && right == nil {
		return nil
	}
	return nil
}

// -----------------------------------------------------------------------------

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	return help(root, p.Val, q.Val)
}
