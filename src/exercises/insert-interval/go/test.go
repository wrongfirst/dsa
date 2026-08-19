Tests.EqualCheck("Example 1", [][]int{{1, 6}}, insert([][]int{{1, 3}, {4, 6}}, []int{2, 5}))
Tests.EqualCheck("Example 2", [][]int{{1, 2}, {3, 5}, {6, 7}, {9, 10}}, insert([][]int{{1, 2}, {3, 5}, {9, 10}}, []int{6, 7}))
