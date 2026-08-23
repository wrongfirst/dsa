h1 := [][]int{{4, 2, 7, 3, 4}, {7, 4, 6, 4, 7}, {6, 3, 5, 3, 6}}
Tests.EqualCheck("Example 1", NormalizeNested([][]int{{0, 2}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 0}}), NormalizeNested(pacificAtlantic(h1)))

h2 := [][]int{{1}, {1}}
Tests.EqualCheck("Example 2", NormalizeNested([][]int{{0, 0}, {1, 0}}), NormalizeNested(pacificAtlantic(h2)))

