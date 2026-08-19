func normalize(groups [][]string) [][]string {
	res := make([][]string, len(groups))
	for i, g := range groups {
		cp := append([]string{}, g...)
		sort.Strings(cp)
		res[i] = cp
	}
	sort.Slice(res, func(i, j int) bool {
		if len(res[i]) != len(res[j]) {
			return len(res[i]) < len(res[j])
		}
		if len(res[i]) > 0 && len(res[j]) > 0 {
			return res[i][0] < res[j][0]
		}
		return false
	})
	return res
}

Tests.EqualCheck("Example 1", normalize([][]string{{"act", "cat"}, {"pots", "tops", "stop"}, {"hat"}}), normalize(groupAnagrams([]string{"act", "pots", "tops", "cat", "stop", "hat"})))
Tests.EqualCheck("Example 2", normalize([][]string{{"x"}}), normalize(groupAnagrams([]string{"x"})))
