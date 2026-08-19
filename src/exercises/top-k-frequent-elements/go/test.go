func sortInts(arr []int) []int {
	res := append([]int{}, arr...)
	sort.Ints(res)
	return res
}

Tests.EqualCheck("Example 1", []int{2, 3}, sortInts(topKFrequent([]int{1, 2, 2, 3, 3, 3}, 2)))
Tests.EqualCheck("Example 2", []int{7}, sortInts(topKFrequent([]int{7, 7}, 1)))
