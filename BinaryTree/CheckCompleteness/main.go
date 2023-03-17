// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isCompleteTree(root *TreeNode) bool {
	if root == nil {
		return true
	}
	queue := []*TreeNode{root}
	for len(queue) > 0 {
		// Getting front element
		front := queue[0]
		// Removing front element
		queue = queue[1:]
		if front == nil {
			break
		}
		// Push left and right child
		queue = append(queue, front.Left, front.Right)
	}
	for _, node := range queue {
		if node != nil {
			return false
		}
	}
	return true
}
