Tests.EqualCheck("Example 1", []int{1, 2, 4, 3}, spiralOrder([][]int{{1, 2}, {3, 4}}))
Tests.EqualCheck("Example 2", []int{1, 2, 3, 6, 9, 8, 7, 4, 5}, spiralOrder([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}))
Tests.EqualCheck("Example 3", []int{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7}, spiralOrder([][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}))
