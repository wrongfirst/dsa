func makeCycle(arr []int, pos int) *ListNode {
	head := ListToLinkedList(arr)
	if pos == -1 || head == nil {
		return head
	}
	var target *ListNode
	tail := head
	idx := 0
	for tail != nil {
		if idx == pos {
			target = tail
		}
		if tail.Next == nil {
			break
		}
		tail = tail.Next
		idx++
	}
	if tail != nil && target != nil {
		tail.Next = target
	}
	return head
}

Tests.BoolCheck("Example 1", hasCycle(makeCycle([]int{1, 2, 3, 4}, 1)) == true)
Tests.BoolCheck("Example 2", hasCycle(makeCycle([]int{1, 2}, -1)) == false)
