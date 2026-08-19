func normalize(coords [][]int) [][]int {
	res := make([][]int, len(coords))
	for i, c := range coords {
		res[i] = append([]int{}, c...)
	}
	sort.Slice(res, func(i, j int) bool {
		if res[i][0] != res[j][0] {
			return res[i][0] < res[j][0]
		}
		return res[i][1] < res[j][1]
	})
	return res
}

h1 := [][]int{{4, 2, 7, 3, 4}, {7, 4, 6, 4, 7}, {6, 3, 5, 3, 6}}
Tests.EqualCheck("Example 1", normalize([][]int{{0, 2}, {0, 4}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 0}}), normalize(pacificAtlantic(h1)))

h2 := [][]int{{1}, {1}}
Tests.EqualCheck("Example 2", normalize([][]int{{0, 0}, {1, 0}}), normalize(pacificAtlantic(h2)))
