Tests.EqualCheck("Example 1", [][]int{{2}, {1, 3}, {2}}, GraphToAdj(cloneGraph(BuildGraph([][]int{{2}, {1, 3}, {2}}))))
Tests.EqualCheck("Example 2", [][]int{{}}, GraphToAdj(cloneGraph(BuildGraph([][]int{{}}))))
Tests.EqualCheck("Example 3", [][]int{}, GraphToAdj(cloneGraph(BuildGraph([][]int{}))))

