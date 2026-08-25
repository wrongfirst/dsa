Tests.EqualCheck("Example 1", []int{1, 1, 2, 3, 4, 5}, LinkedListToList(mergeTwoLists(ListToLinkedList([]int{1, 2, 4}), ListToLinkedList([]int{1, 3, 5}))))
Tests.EqualCheck("Example 2", []int{1, 2}, LinkedListToList(mergeTwoLists(ListToLinkedList([]int{}), ListToLinkedList([]int{1, 2}))))
