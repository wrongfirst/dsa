Tests.BoolCheck("Example 1", validTree(5, [][]int{{0, 1}, {0, 2}, {0, 3}, {1, 4}}) == true)
Tests.BoolCheck("Example 2", validTree(5, [][]int{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}}) == false)
