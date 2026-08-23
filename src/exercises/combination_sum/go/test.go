Tests.EqualCheck("Example 1", NormalizeNested([][]int{{2, 2, 5}, {9}}), NormalizeNested(combinationSum([]int{2, 5, 6, 9}, 9)))
Tests.EqualCheck("Example 2", NormalizeNested([][]int{{3, 3, 3, 3, 4}, {3, 3, 5, 5}, {4, 4, 4, 4}, {3, 4, 4, 5}}), NormalizeNested(combinationSum([]int{3, 4, 5}, 16)))
Tests.EqualCheck("Example 3", [][]int{}, combinationSum([]int{3}, 5))

