m1 := [][]int{{0, 0}, {0, 0}}
setZeroes(m1)
Tests.EqualCheck("Example 1", [][]int{{0, 0}, {0, 0}}, m1)

m2 := [][]int{{1, 0, 3}, {0, 0, 0}, {6, 0, 8}}
setZeroes(m2)
Tests.EqualCheck("Example 2", [][]int{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, m2)
