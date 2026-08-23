h1 := ListToLinkedList([]int{2, 4, 6, 8})
reorderList(h1)
Tests.EqualCheck("Example 1", []int{2, 8, 4, 6}, LinkedListToList(h1))

h2 := ListToLinkedList([]int{2, 4, 6, 8, 10})
reorderList(h2)
Tests.EqualCheck("Example 2", []int{2, 10, 4, 8, 6}, LinkedListToList(h2))
