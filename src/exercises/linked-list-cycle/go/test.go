Tests.BoolCheck("Example 1", hasCycle(MakeCycle([]int{1, 2, 3, 4}, 1)) == true)
Tests.BoolCheck("Example 2", hasCycle(MakeCycle([]int{1, 2}, -1)) == false)

