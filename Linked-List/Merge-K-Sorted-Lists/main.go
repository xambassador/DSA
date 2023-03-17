package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	// If l1 is nil, return l2
	if l1 == nil {
		return l2
	}
	// If l2 is nil, return l1
	if l2 == nil {
		return l1
	}
	// If l1.Val is less than l2.Val, then l1.Next is the result of merging l1.Next and l2
	if l1.Val < l2.Val {
		l1.Next = mergeTwoLists(l1.Next, l2)
		return l1
	}

	// If l2.Val is less than l1.Val, then l2.Next is the result of merging l1 and l2.Next
	l2.Next = mergeTwoLists(l1, l2.Next)
	return l2
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}
	if len(lists) == 2 {
		return mergeTwoLists(lists[0], lists[1])
	}
	return mergeTwoLists(mergeKLists(lists[:len(lists)/2]), mergeKLists(lists[len(lists)/2:]))
}
