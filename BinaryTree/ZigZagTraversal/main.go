package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(root *TreeNode, level int, res *[][]int) {
	// If root is nil, return
	if root == nil {
		return
	}
	// If the level is equal to the length of the result array
	if level == len(*res) {
		// Create a new array and add it to the result array
		*res = append(*res, []int{})
	}
	// If level is even, add the value to the end of the array
	if level%2 == 0 {
		(*res)[level] = append((*res)[level], root.Val)
	} else {
		// If level is odd, add the value to the beginning of the array
		(*res)[level] = append([]int{root.Val}, (*res)[level]...)
	}
	// Call the helper function for left and right child
	helper(root.Left, level+1, res)
	helper(root.Right, level+1, res)
}

// Using recursion
func zigzagLevelOrderUsingRecursion(root *TreeNode) [][]int {
	// If root is nil, return nil
	if root == nil {
		return nil
	}
	// Result array
	var res [][]int
	// Call the helper function
	helper(root, 0, &res)
	return res
}

// Using queue
func zigzagLevelOrder(root *TreeNode) [][]int {
	// If root is nil, return nil
	if root == nil {
		return nil
	}
	// Create a queue to store the nodes
	var res [][]int
	var queue []*TreeNode
	// Add root to the queue
	queue = append(queue, root)
	// level of the tree
	var level int
	// While queue is not empty
	for len(queue) > 0 {
		// Create a temp array to store the values
		var tmp []int
		// Create a next array to store the next level nodes
		var next []*TreeNode
		// Iterate over the queue
		for _, node := range queue {
			if level%2 == 0 {
				tmp = append(tmp, node.Val)
			} else {
				tmp = append([]int{node.Val}, tmp...)
			}
			if node.Left != nil {
				next = append(next, node.Left)
			}
			if node.Right != nil {
				next = append(next, node.Right)
			}
		}
		res = append(res, tmp)
		queue = next
		level++
	}
	return res
}

// Using two stacks
func zigzagLevelOrderUsingStack(root *TreeNode) [][]int {
	// If root is nil, return nil
	if root == nil {
		return nil
	}
	// Result array
	var res [][]int
	// Create two stacks
	var stack1 []*TreeNode
	var stack2 []*TreeNode

	// Add root to stack1
	stack1 = append(stack1, root)
	// level of the tree
	var level int
	// While both stacks are not empty
	for len(stack1) > 0 || len(stack2) > 0 {
		var tmp []int // temp array to store the values
		// If level is even, pop from stack1 and push to stack2 (left to right)
		if level%2 == 0 {
			for len(stack1) > 0 {
				node := stack1[len(stack1)-1]   // Get the top element
				stack1 = stack1[:len(stack1)-1] // Remove the top element
				tmp = append(tmp, node.Val)     // Add the value to temp array
				// Push the left and right child to stack2
				if node.Left != nil {
					stack2 = append(stack2, node.Left)
				}
				if node.Right != nil {
					stack2 = append(stack2, node.Right)
				}
			}
		} else {
			for len(stack2) > 0 {
				node := stack2[len(stack2)-1]   // Get the top element
				stack2 = stack2[:len(stack2)-1] // Remove the top element
				tmp = append(tmp, node.Val)     // Add the value to temp array
				if node.Right != nil {
					stack1 = append(stack1, node.Right)
				}
				if node.Left != nil {
					stack1 = append(stack1, node.Left)
				}
			}
		}
		// Add the temp array to result array
		res = append(res, tmp)
		// Increment the level
		level++
	}
	return res
}
