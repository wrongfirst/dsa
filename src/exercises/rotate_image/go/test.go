m1 := [][]int{{3, 1}, {4, 2}}
rotate(m1)
Tests.EqualCheck("Example 1", [][]int{{4, 3}, {2, 1}}, m1)

m2 := [][]int{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}
rotate(m2)
Tests.EqualCheck("Example 2", [][]int{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}}, m2)
