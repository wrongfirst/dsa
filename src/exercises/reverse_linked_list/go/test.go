Tests.EqualCheck("Example 1", []int{3, 2, 1, 0}, LinkedListToList(reverseList(ListToLinkedList([]int{0, 1, 2, 3}))))
Tests.EqualCheck("Example 2", []int{}, LinkedListToList(reverseList(ListToLinkedList([]int{}))))
