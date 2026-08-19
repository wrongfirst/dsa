func normalize(groups [][]int) [][]int {
	res := make([][]int, len(groups))
	for i, g := range groups {
		cp := append([]int{}, g...)
		sort.Ints(cp)
		res[i] = cp
	}
	sort.Slice(res, func(i, j int) bool {
		if len(res[i]) != len(res[j]) {
			return len(res[i]) < len(res[j])
		}
		for k := 0; k < len(res[i]); k++ {
			if res[i][k] != res[j][k] {
				return res[i][k] < res[j][k]
			}
		}
		return false
	})
	return res
}

Tests.EqualCheck("Example 1", normalize([][]int{{2, 2, 5}, {9}}), normalize(combinationSum([]int{2, 5, 6, 9}, 9)))
Tests.EqualCheck("Example 2", normalize([][]int{{3, 3, 3, 3, 4}, {3, 3, 5, 5}, {4, 4, 4, 4}, {3, 4, 4, 5}}), normalize(combinationSum([]int{3, 4, 5}, 16)))
Tests.EqualCheck("Example 3", [][]int{}, combinationSum([]int{3}, 5))
