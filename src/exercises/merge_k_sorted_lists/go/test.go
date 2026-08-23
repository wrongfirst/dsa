Tests.EqualCheck("Example 1", []int{1, 1, 2, 3, 3, 4, 5, 6}, LinkedListToList(mergeKLists([]*ListNode{ListToLinkedList([]int{1, 2, 4}), ListToLinkedList([]int{1, 3, 5}), ListToLinkedList([]int{3, 6})})))
Tests.EqualCheck("Example 2", []int{}, LinkedListToList(mergeKLists([]*ListNode{})))
Tests.EqualCheck("Example 3", []int{}, LinkedListToList(mergeKLists([]*ListNode{ListToLinkedList([]int{})})))
