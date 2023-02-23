package main

import (
	"container/heap"
	"sort"
)

type IntHeap []int

func (h IntHeap) Len() int { return len(h) }

func (h IntHeap) Less(i, j int) bool {
	return h[i] > h[j]
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// Leetcode 502. IPO (Hard)
func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	n := len(profits)
	// Pair of capital and profit
	type pair struct {
		c, p int
	}
	// Create a pair array
	arr := make([]pair, n)
	// Initialize the pair array
	for i := 0; i < n; i++ {
		arr[i] = pair{capital[i], profits[i]}
	}
	// Sort the pair array by capital
	sort.Slice(arr, func(i, j int) bool {
		return arr[i].c < arr[j].c
	})
	// Create a max heap
	pq := &IntHeap{}
	heap.Init(pq)
	i := 0
	// Iterate k times
	for ; k > 0; k-- {
		// Push all the profits that can be invested
		for i < n && arr[i].c <= w {
			heap.Push(pq, arr[i].p)
			i++
		}
		// If no profits can be invested, break
		if pq.Len() == 0 {
			break
		}
		// Invest the max profit
		w += heap.Pop(pq).(int)
	}
	return w
}
