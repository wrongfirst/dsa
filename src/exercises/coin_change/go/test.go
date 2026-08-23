Tests.EqualCheck("Example 1", 3, coinChange([]int{1, 2, 5}, 11))
Tests.EqualCheck("Example 2", -1, coinChange([]int{2}, 3))
Tests.EqualCheck("Example 3", 0, coinChange([]int{1}, 0))
