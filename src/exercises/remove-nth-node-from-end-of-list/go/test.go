Tests.EqualCheck("Example 1", []int{1, 2, 4}, LinkedListToList(removeNthFromEnd(ListToLinkedList([]int{1, 2, 3, 4}), 2)))
Tests.EqualCheck("Example 2", []int{}, LinkedListToList(removeNthFromEnd(ListToLinkedList([]int{5}), 1)))
