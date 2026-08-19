Tests.EqualCheck("Example 1", [][]int{{1}, {2, 3}, {4, 5, 6, 7}}, levelOrder(IntsToTree(1, 2, 3, 4, 5, 6, 7)))
Tests.EqualCheck("Example 2", [][]int{{1}}, levelOrder(IntsToTree(1)))
Tests.EqualCheck("Example 3", [][]int{}, levelOrder(nil))
