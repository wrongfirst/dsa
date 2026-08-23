Tests.EqualCheck("Example 1", [][]int{{1, 5}, {6, 7}}, merge([][]int{{1, 5}, {1, 5}, {6, 7}}))
Tests.EqualCheck("Example 2", [][]int{{1, 3}}, merge([][]int{{1, 3}, {2, 3}}))
